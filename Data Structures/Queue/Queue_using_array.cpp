/*
Problem Statement: Implement queue using array along with its  functionalities like:
1. Enqueue.
2. Dequeue.
3. Traversal of the queue.
4. Check for empty queue.
5. Check for full queue.
*/

#include <bits/stdc++.h>
using namespace std;

//We are creating a class for array
class Queue
{
private:
    int front;
    int rear;
    int capacity;
    int *ptr;

public:
    //Constructor to initialize the data members of Queue class
    Queue(int capacity)
    {
        front = -1;
        rear = -1;
        this->capacity = capacity;
        ptr = new int[capacity];
    }

    //Checking if the Queue is empty or not
    bool isEmpty()
    {
        if (front == rear)
        {
            if (rear == capacity - 1)
                return false;
            else
                return true;
        }
        return false;
    }

    //Checking if the Queue is full or not
    bool isFull()
    {
        if ((rear + 1) % capacity == front)
            return true;
        return false;
    }

    //Inserting data into the queue
    void enQueue()
    {
        if (isFull())
            cout << "\nQueue is Full" << endl;
        else
        {
            int data;
            cout << "\nEnter data to be inserted : ";
            cin >> data;
            if (rear == -1)
            {
                ptr[0] = data;
                rear = front = 0;
                cout << data << " is inserted at rear = " << rear << " and front = " << front;
            }
            else
            {
                rear = (rear + 1) % capacity;
                ptr[rear] = data;
                cout << data << " is inserted at rear = " << rear << " and front = " << front;
            }
        }
    }

    //Deleting data from the queue
    void deQueue()
    {
        if (isEmpty())
            cout << "\nQueue is Empty" << endl;
        else
        {
            cout << endl
                 << ptr[front] << "  is deleted from Queue" << endl;
            cout << "front is : " << front;
            if (front == capacity - 1)
                front = rear = -1;
            else
                front = (front + 1) % capacity;
        }
    }

    //Traversing queue and printing data
    void display()
    {
        int i;
        if (isEmpty())
            cout << "\nQueue is Empty" << endl;
        else
        {
            cout << "Queue is : ";
            for (i = front; i != rear; i = (i + 1) % capacity)
                cout << ptr[i] << "   ";
            cout << ptr[rear] << endl;
        }
    }
};

//Driver Program
int main()
{
    int cap, choice;
    cout << "Enter the size or capacity of Queue : ";
    cin >> cap;
    Queue q(cap);
    while (1)
    {
        cout << endl;
        cout << "1. To enter data into queue." << endl;
        cout << "2. To delete data from queue." << endl;
        cout << "3. To display the data." << endl;
        cout << "4. TO EXIT." << endl;

        cout << "\nENTER YOUR CHOICE... : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.enQueue();
            break;

        case 2:
            q.deQueue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "\nINVALID CHOICE..." << endl;
        }
    }
    return 0;
}

/*
    Time Complexities:
    Enqueue --> O(1)
    DeQueue --> O(1)
    IsEmpty --> O(1)
    IsFull  --> O(1)

    Space Complexity: O(n) [for array]
    ----------------------------------
    Sample Input - Output :

    Enter the size or capacity of Queue : 5

    1. To enter data into queue.
    2. To delete data from queue.
    3. To display the data.
    4. TO EXIT.

    ENTER YOUR CHOICE... : 1

    Enter data to be inserted : 10

    1. To enter data into queue.
    2. To delete data from queue.
    3. To display the data.
    4. TO EXIT.

    ENTER YOUR CHOICE... : 1

    Enter data to be inserted : 20

    1. To enter data into queue.
    2. To delete data from queue.
    3. To display the data.
    4. TO EXIT.

    ENTER YOUR CHOICE... : 1

    Enter data to be inserted : 30

    1. To enter data into queue.
    2. To delete data from queue.
    3. To display the data.
    4. TO EXIT.

    ENTER YOUR CHOICE... : 1

    Enter data to be inserted : 40

    1. To enter data into queue.
    2. To delete data from queue.
    3. To display the data.
    4. TO EXIT.

    ENTER YOUR CHOICE... : 3
    Queue is : 10   20   30   40

    1. To enter data into queue.
    2. To delete data from queue.
    3. To display the data.
    4. TO EXIT.

    ENTER YOUR CHOICE... : 2

    10  is deleted from Queue

    1. To enter data into queue.
    2. To delete data from queue.
    3. To display the data.
    4. TO EXIT.

    ENTER YOUR CHOICE... : 1

    Enter data to be inserted : 50

    1. To enter data into queue.
    2. To delete data from queue.
    3. To display the data.
    4. TO EXIT.

    ENTER YOUR CHOICE... : 3
    Queue is : 20   30   40   50

    1. To enter data into queue.
    2. To delete data from queue.
    3. To display the data.
    4. TO EXIT.

    ENTER YOUR CHOICE... : 4

*/
