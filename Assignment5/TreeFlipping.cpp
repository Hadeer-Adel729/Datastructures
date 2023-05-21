#include<iostream>
#include <queue>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* root = nullptr;

/* function that allocates a new node
with the given data and NULL left and right
pointers. */
struct Node* newNode(int data)

{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    if (root == nullptr)
    {
        root = node;
    }
    return(node);
}

/* Function to convert a given binary tree into its mirror*/
void flip(Node* node = root)
{
    /*base case: if the tree is empty */
    if (node == NULL)
        return;
    else
    {
        struct Node* temp;

        /*convert left subtree */
        flip(node->left);

        /*convert right subtree */
        flip(node->right);

        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}


/* function to print Inorder traversal.*/
void DisplayTree(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }
    DisplayTree(node->left);
    cout << node->data << " ";
    DisplayTree(node->right);
}


/* Driver Functions to test mirror() */

void Test1()
{
    struct Node *root = newNode(1);
    root->left	 = newNode(2);
    root->right	 = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    /* Print the input tree */
    cout << "Test1 : " << endl;
    cout << "------" << endl << endl;
    cout << "The Original tree is" << endl;
    DisplayTree(root);
    cout << endl << endl;

    /* Convert tree to its mirror */
    flip();

    /* Print the mirror tree */
    cout <<"\nThe New tree is" << endl;
    DisplayTree(root);

    cout << endl << "*----------------------------------------------*"<<endl << endl;
    /*
       4
      / \
     2   5
    / \
    1   3

    is changed to...
       4
      / \
     5   2
        / \
       3   1
    */

}

void Test2()
{
    struct Node *root = newNode(4);
    root->left	 = newNode(2);
    root->right	 = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    /* Print the input tree */
    cout << "Test2 : " << endl;
    cout << "------" << endl << endl;
    cout << "The Original tree is" << endl;
    DisplayTree(root);
    cout << endl << endl;

    /* Convert tree to its mirror */
    flip(root);

    /* Print the mirror tree */
    cout <<"\nThe New tree is" << endl;
    DisplayTree(root);

    cout << endl << "*----------------------------------------------*"<<endl << endl;
    /*
       1
      / \
     2   3
    / \
    4   5

    is changed to...
       1
      / \
     3   2
        / \
       5   4
    */

}

void Test3 ()
{
    struct Node *root = newNode(4);
    root->left	 = newNode(1);
    root->right	 = newNode(2);
    root->right->left = newNode(5);
    root->right->right = newNode(3);

    /* Print the input tree */
    cout << "Test3 : " << endl;
    cout << "------" << endl << endl;
    cout << "The Original tree is" << endl;
    DisplayTree(root);
    cout << endl << endl;

    /* Convert tree to its mirror */
    flip(root);

    /* Print the mirror tree */
    cout <<"\nThe New tree is" << endl;
    DisplayTree(root);

    cout << endl << "*----------------------------------------------*"<<endl << endl;
    /*
       1
      / \
     4   5
        / \
        2  3


    is changed to...
       1
      / \
     5   4
    / \
    3   2
    */

}
void Test4()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    /* Print the input tree */
    cout << "Test4 : " << endl;
    cout << "------" << endl << endl;
    cout << "The Original tree is" << endl;
    DisplayTree(root);
    cout << endl << endl;

    /* Convert tree to its mirror */
    flip(root);

    /* Print the mirror tree */
    cout <<"\nThe New tree is" << endl;
    DisplayTree(root);

    cout << endl << "*----------------------------------------------*"<<endl << endl;
    /*
        1
      /   \
     2      3
    / \    / \
    4   5  6   7


    is changed to...
        1
      /   \
     3      2
    / \    / \
    7  6   5   4

    */

}
void Test5()
{
    struct Node *root = newNode(1);
    root->left	 = newNode(2);
    root->right	 = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);

    /* Print the input tree */
    cout << "Test5 : " << endl;
    cout << "------" << endl << endl;
    cout << "The Original tree is" << endl;
    DisplayTree(root);
    cout << endl << endl;

    /* Convert tree to its mirror */
    flip(root);

    /* Print the mirror tree */
    cout <<"\nThe New tree is" << endl;
    DisplayTree(root);

    cout << endl << "*----------------------------------------------*"<<endl << endl;
    /*
       1
      / \
     2   3
    /    /
    4     5

    is changed to...
       1
      / \
     3   2
      \    \
       5    4
    */

}



int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

