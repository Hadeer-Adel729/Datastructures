#include <iostream>
#include <queue>
using namespace std;


class myQueue
{
private:
    vector<int> q;
public:
    void push(int value)
    {
        q.insert(q.end(),value);
    }

    void pop()
    {
        q.erase(q.begin());
    }
    int Front()
    {
        return *q.begin();
    }
    int Size()
    {
        return q.size();
    }
    void Display_Queue()
    {
        for (int i = 0; i < q.size(); i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
        return;
    }
};

/*---------------------------------------------------------------------*/

class Stack
{

    myQueue q;

public:

    void Push(int x)
    {
        int siz = q.Size();
        q.push(x);
        for (int i = 0; i < siz; i++)
        {

            q.push(q.Front());
            q.pop();
        }
    }

    /* � removes the top element.*/
    int Pop()
    {
        int n = q.Front();
        q.pop();
        return n;
    }

    /*� returns the top element.*/
    int Top()
    {
        return q.Front();
    }
    int Size()
    {
        return q.Size();
    }
};
    /* function to display the elements of stack*/
    void Print_Stack(Stack s)
    {
        // If stack is empty
        if (s.Size() == 0)
            return;

    // Extract top of the stack
        int t = s.Top();

        // Pop the top element
        s.Pop();

        // Print the current top
        // of the stack i.e., x
        cout << t << ' ' << endl;

        // Proceed to print
    // remaining stack
        Print_Stack(s);

        // Push the element back
        s.Push(t);
    }

int main()
{
    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);

    cout << "Elements of stack now is : " << endl;
    Print_Stack(s);
    cout << endl << endl;

    cout << "Size of the stack : " << s.Size() << endl << endl;

    cout << "Top of the stack: " << s.Top() << endl << endl;

    cout << "The deleted element is: " << s.Pop() << endl << endl;
    cout << "Elements of stack now is : " << endl;
    Print_Stack(s);
    cout << endl << endl;

    cout << "Top of the stack after removing element: " << s.Top() << endl << endl;

    cout << "Size of the stack after removing element: " << s.Size() << endl << endl;


}
