#include <iostream>
using namespace std;
//class represent information of interval of node
class Interval_info
{
public:
    int low;//each interval have lower bound
    int high;//each interval have Upper bound
};
//class represent information of Node
class Node
{
public:
    Interval_info *interval;//Each node have interval
    Node *left;//Each Node have left Subtree
    Node *right;//Each Node have right Subtree
    int Max;//Each Node have Max (Highest high of subtree)
};
//Create new node with its informations
Node *newNode(Interval_info interval)
{
    Node *NewNode = new Node();
    NewNode->interval = new Interval_info(interval);//taking given interval as interval of this new node
    NewNode->Max = interval.high;//make max of this new node equal its high because it have not yet subtreees
    NewNode->left = NewNode->right = NULL;//make left and right of this new node equal NULL because it have not yet subtreees
    return NewNode;//return this node
}
//insert tree
Node *Insert(Node *root, Interval_info interval)
{
    if (root == NULL) //if root equal Null means tree is empty make new node and make it root of tree
        return newNode(interval);
    if (interval.low < (root->interval->low))//if low of interval less than current node low go to Subtree to insert this New node
        root->left = Insert(root->left, interval);
    else
        root->right = Insert(root->right, interval);//if low of interval greater than or qual current node low go to Subtree to insert this New node
    //Update Max values
    if (root->Max < interval.high)
        root->Max = interval.high;
    return root;
}
//insert tree
void update_Max_Value(Node *root, Interval_info interval)
{
    if (root == NULL)
        return;
    if (interval.low < (root->interval->low))//if low of interval less than current node low go to Subtree
        update_Max_Value(root->left, interval);
    else
        update_Max_Value(root->right, interval);//if low of interval greater than or qual current node low go to Subtree
    //Update Max values
    if (root->Max >= interval.high)
    {
        if (root->right != NULL && root->interval->high < root->right->Max)
            root->Max = root->right->Max;
        else if (root->left != NULL && root->interval->high < root->left->Max)
            root->Max = root->left->Max;
        else
            root->Max = root->interval->high;
    }
    return;
}
//we get here successor but we already go right one time and we call this function if there was 2 children
Node *get_successor(Node *node)
{
    Node *current = node;
    //we go down to get the left most
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
//this function delete one node from interval node
Node *remove(Node *root, Interval_info interval)
{
    int LowItem = interval.low;
    int HighItem = interval.high;
    if (root == NULL)
        return root;
    //If the LowItem smaller than LowItem in Interval tree, so we will go left
    if (LowItem < root->interval->low)
        root->left = remove(root->left, interval);

    //If the LowItem bigger than LowItem in Interval tree,so we will go right
    else if (LowItem > root->interval->low)
        root->right = remove(root->right, interval);
    /*If the LowItem equal LowItem in Interval tree
      and the HighItem equal HighItem in Interval tree
      so it was the node that will be deleted to be deleted*/
    else if (LowItem == root->interval->low && HighItem == root->interval->high)
    {
        //no child,so only delete root
        if (root->left == NULL && root->right == NULL)
            return NULL;
        //node have only left child
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        //node have only right child
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        //node has two children, so we get inorder successor
        //[smallest in the right subtree]
        Node *temp = get_successor(root->right);
        //we copy successor in this node
        root->interval->low = temp->interval->low;
        root->interval->high = temp->interval->high;
        //this is tempratory opject from Interval_info class
        Interval_info tt;
        tt.low = temp->interval->low;
        tt.high = temp->interval->high;
        //Delete the inorder successor
        root->right = remove(root->right, tt);
    }
    return root;
}
//this function returns new tree after delete one node
Node* DeleteInterval(Node *root, Interval_info interval)
{
    //call the remove function
    root = remove(root, interval);
    //after remove the interval , update the tree and max height
    update_Max_Value(root, interval);
    //return new tree after delete the interval
    return root;
}
//function to print the tree in order (left->root->right)
void Inorder(Node *root)
{
//base case,tree is empty
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << "[" << root->interval->low << "," << root->interval->high << "]"
         << " Max= " << root->Max << endl;
    Inorder(root->right);
}
//function to display the tree in order , and check if the tree is empty will display message that tree is empty
//otherwise will return the tree
void  print(Node* root)
{
    if (root == NULL)
        cout << "\nNow Tree is empty!" << endl;
    else
        Inorder(root);
}
//function to check if two intervals overlap or not
bool IsOverlap(Interval_info query1 , Interval_info query2)
{
     //two intervals will overlap if the low of query1 <= high of query2
    //and if the low of query2 <= high of query1
    if (query1.low <= query2.high && query2.low <= query1.high)
        return true;
    return false;
}
//The main function that searches for a given interval query in a given Interval Tree
Interval_info *Search(Node *root , Interval_info query)
{
    //Base Case,tree is empty
    if (root == NULL)
        return NULL;
    //check If given query overlaps with root
    if(IsOverlap(*(root->interval) , query))
        return root->interval;
  /*If left child of root is present and max of left child is
    greater than or equal to given interval,then query may
    overlap with an interval in left subtree */
    if(root->left != NULL && query.low <= root->left->Max)
        return Search(root->left , query);
    //Else query can only overlap with right subtree
    return Search(root->right,query);
}
/*Function to return all all intervals overlapping with the parameter interval,
by first getting one overlapping interval,then deleting it, and so on.
Then, all such intervals must be inserted again in the tree to restore its status*/
void SearchAll(Node *root , Interval_info query)
{
    //array of intervals to store all intervals that will be deleted, if they are overlapping the query.
    Interval_info InsertInterval[100];
    int counter = 0;//counter to count the intervals that overlapped with the query
    while(root != NULL )
    {
    //result is an pointer to interval that stores the return value from function search(root,query)
        Interval_info *result = Search(root, query);
        if (result == NULL)
            break;
        cout << "\nInterval [" << query.low << "," << query.high << "]";
        cout << " Overlaps with [" << result->low << "," << result->high << "]" << endl;
         //deletedNode is an interval stores the same values of (result) interval ,to pass it to function (DeleteInterval)
        //and store it in the (InsertInterval) array,to use it later to insert the overlapped intervals to the tree
        Interval_info deletedNode;
        //set the high of (deletedNode) interval with the high of the returned interval"result" from function search
        deletedNode.high =  result->high;
        //set the low of (deletedNode) interval with the low of the returned interval"result" from function search
        deletedNode.low =  result->low;
        //here we add the overlapped interval to the array of intervals
        InsertInterval[counter].high = deletedNode.high;
        InsertInterval[counter].low = deletedNode.low;
        counter++; //increment the number of overlapped intervals
        root = DeleteInterval(root , deletedNode);//delete the interval that overlapped with the given query
    }
    //means that we could not find any interval overlaps with the given query
    if(counter==0)
    {
        cout << "\nInterval [" << query.low << "," << query.high << "]";
        cout << " is not Overlapping with any Interval in the tree!\n";
    }
    else
    {
    //here we insert back to the tree the overlapped intervals that was deleted while searching
        for (int i = 0; i < counter; i++)
        root = Insert(root, InsertInterval[i]);
   }
}
int main()
{
    //test insert
    Interval_info intervals1[] = {{17, 19}, {5, 8}, {21, 24}, {4, 8}, {15, 18}, {7, 10},{16,22}};
    int Size1 = sizeof(intervals1) / sizeof(intervals1[0]);
    Node *root1 = NULL;
    for (int i = 0; i < Size1; i++)
        root1 = Insert(root1,intervals1[i]);
    //print tree
    cout << "Print tree in order" << endl;
    print(root1);
    //search for query that does not overlap with any interval in the tree
    Interval_info query1 = {12,14};
    SearchAll(root1,query1);
    //search for query that overlaps with an interval in the left sub tree
    //result->(5,8),(4,8),(7,10)
    query1 = {6,14};
    SearchAll(root1,query1);
    //search for query that overlaps with an interval in the right sub tree
    //result->(21,24)
    query1 = {23,24};
    SearchAll(root1,query1);
    //search for query that overlaps with an intervals in the right sub tree&left sub tree
    //result ->(21,24) , (16 , 22)
    query1 = {20,22};
    SearchAll(root1 , query1);
    //delete the tree
    for(int i=0; i< Size1; i++)
        root1 = DeleteInterval(root1,intervals1[i]);
    //print tree after deletion,return that tree is empty
    print(root1);
    cout << "----------------------------------------------------" << endl;
    //test case
    Interval_info intervals2[] = {{15, 20}, {10, 30}, {17, 19},{5, 20}, {12, 15}, {30, 40}};
    int Size2 = sizeof(intervals2) / sizeof(intervals2[0]);
    Node *root2 = NULL;
    for (int i = 0; i < Size2; i++)
        root2 = Insert(root2, intervals2[i]);
    //print tree
    cout << "\nPrint tree in order" << endl;
    Inorder(root2);
    //search for query that overlaps interval in the left sub tree
    //result->(5,20)
    Interval_info query2 = {6,7};
    SearchAll(root2,query2);
    //search for query that overlaps interval in the right sub tree
    //result-> (30,40)
    query2 = {31,32};
    SearchAll(root2,query2);
    //search for query that overlaps with an intervals in the right sub tree&left sub tree
    //result->(15,20),(17,19),(10,30),(12,15),(5,20)
    query2 = {6,17};
    SearchAll(root2,query2);
    //search for query that don't overlap with ant interval in the tree
    query2 = {50,79};
    SearchAll(root2,query2);
    //Delete the tree
    for(int i=0; i< Size2; i++)
        root2 = DeleteInterval(root2,intervals2[i]);
    print(root2);
    cout << "----------------------------------------------------" << endl;
    //test case
    Interval_info intervals3[] = { {20,36}, {3, 41}, {29, 99},{0, 1}, {10, 15}};
    int Size3 = sizeof(intervals3) / sizeof(intervals3[0]);
    Node *root3 = NULL;
    for (int i = 0; i < Size3; i++)
        root3 = Insert(root3,intervals3[i]);
    //print tree
    cout << "\nPrint tree in order" << endl;
    Inorder(root3);
    //search for query that overlaps with intervals in the left sub tree
    //result-> (10,15) , (3,41)
    Interval_info query3 = {9,14};
    SearchAll(root3,query3);
    //search for query that overlaps with intervals in the right sub tree
    //result->(29,99)
    query3 = {42,45};
    SearchAll(root3,query3);
    //search for query that overlaps with intervals in the right sub tree&left sub tree
    //result->(3,41),(29,99)
    query3 = {41,42};
    SearchAll(root3,query3);
    //search for query that don't overlap with ant interval in the tree
    query3 = {100,110};
    SearchAll(root3,query3);
    //Delete the tree
    for(int i=0; i< Size3; i++)
        root3 = DeleteInterval(root3,intervals3[i] );
    print(root3);
    cout << "----------------------------------------------------" << endl;
    //test case
    Interval_info intervals4[] = {{15,40}, {10, 28}, {16, 23},{5, 24}, {11, 16} , {18,60}};
    int Size4 = sizeof(intervals4) / sizeof(intervals4[0]);
    Node *root4 = NULL;
    for (int i = 0; i < Size4; i++)
        root4 = Insert(root4,intervals4[i]);
    //print tree
    cout << "\nPrint tree in order" << endl;
    Inorder(root4);
    //search for query that overlaps with intervals in the left sub tree
   //result->(5,24)
    Interval_info query4 = {6,7};
    SearchAll(root4,query4);
    //search for query that overlaps with an interval in the right sub tree
    //result->(29,99)
    query4 = {42,50};
    SearchAll(root4,query4);
    //search for query that don't overlap with an interval in the tree
    query4 = {66,75};
    SearchAll(root4,query4);
    //search for query that overlaps with intervals in the right sub tree&left subtree
    //result->(10,28),(16,23),(5,24),(11,16),(15,40)
    query4 = {15,17};
    SearchAll(root4,query4);
    //Delete the tree
    for(int i=0; i< Size4; i++)
        root4 = DeleteInterval(root4,intervals4[i]);
    print(root4);
    cout << "----------------------------------------------------" << endl;
    //test case
    Interval_info intervals5[] = {{5,10}, {3, 8}, {10, 15},{1, 1}, {9, 11} , {16,18}};
    int Size5 = sizeof(intervals5) / sizeof(intervals5[0]);
    Node *root5 = NULL;
    for (int i = 0; i < Size5; i++)
        root5 = Insert(root5, intervals5[i]);
    //print tree
    cout << "\nPrint tree in order" << endl;
    Inorder(root5);
    //search for query that overlaps with intervals in the left sub tree
    //result-> (3,8)
    Interval_info query5 = {2,4};
    SearchAll(root5,query5);
    //search for query that overlaps with an interval in the right sub tree
    //result-> (16,18)
    query5 = {17,18};
    SearchAll(root5,query5);
    //search for query that don't overlap with an interval in the tree
    query5 = {66,75};
    SearchAll(root5,query5);
    //search for query that overlaps with intervals in the right sub tree&left subtree
    //result->(3,8),(9,11),(5,10)
    query5 = {2,9};
    SearchAll(root5,query5);
    //Delete the tree
    for(int i=0; i< Size5; i++)
        root5 = DeleteInterval(root5,intervals5[i]);
    print(root5);
    return 0;
}
