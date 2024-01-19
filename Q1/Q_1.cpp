#include <iostream>
#include "dequeue.h"
#include "maxheap.h"
using namespace std;

int main()
{
    while (true)
    {
        cout << "What would you like to test?" << endl;
        cout << "Enter 1 for linked list" << endl;
        cout << "Enter 2 for Heap" << endl;
        cout << "Enter 3 for Dequeue" << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            int val;
            cout << "Enter the first element of the linked list" << endl;
            cin >> val;
            LinkedList *list = new LinkedList(val);

            while (true)
            {
                cout << endl;
                cout << "What would you like to do further?" << endl;
                cout << "Enter 1 to add element at front" << endl;
                cout << "Enter 2 to add element at end" << endl;
                cout << "Enter 3 to remove element from front" << endl;
                cout << "Enter 4 to remove element from back" << endl;
                cout << "Enter 5 to get the front element" << endl;
                cout << "Enter 6 to get the last element" << endl;
                cout << "Enter 7 to traverse the linked list" << endl;
                cout << "Enter any other key to exit loop" << endl;
                cout << endl;
                cin >> n;
                if (n == 1)
                {
                    cin >> val;
                    list->insert_at_start(val);
                }
                else if (n == 2)
                {
                    cin >> val;
                    list->insert_at_end(val);
                }
                else if (n == 3)
                {
                    list->remove_from_start();
                }
                else if (n == 4)
                {
                    list->remove_from_end();
                }
                else if (n == 5)
                {
                    int front = list->front();
                    cout << front << endl;
                }
                else if (n == 6)
                {
                    int last = list->last();
                    cout << last << endl;
                }
                else if (n == 7)
                {
                    list->traverse();
                }
                else
                    break;
            }
        }
        else if (n == 2)
        {
            int val;
            cout << "Enter the root element of the heap" << endl;
            MaxHeap* heap = new MaxHeap();
            cout << endl;

            while(true){
                cout<<endl;
                cout << "What would you like to do further?" << endl;
                cout << "Enter 1 to add element to heap" << endl;
                cout << "Enter 2 to get the max element" << endl;
                cout << "Enter 3 to get the max element and remove it from heap" << endl;
                cout<<endl;
                cin>>n;
                if(n == 1){
                    cin>>val;
                    heap->add(val);
                }
                else if(n==2){
                    int max = heap->max();
                    cout<<max<<endl;
                }
                else if(n==3){
                    int max = heap->remove_maxt();
                    cout<<max<<endl;
                }
                else break;
            }
        }
        else if (n == 3)
        {
            int val;
            cout << "Enter the first element to initialise the dequeue" << endl;
            cin >> val;
            Dequeue *q = new Dequeue(val);
            while (true)
            {
                cout << endl;
                cout << "What would you like to do further?" << endl;
                cout << "Enter 1 for push_front()" << endl;
                cout << "Enter 2 for push_back()" << endl;
                cout << "Enter 3 for pop_front()" << endl;
                cout << "Enter 4 for pop_back()" << endl;
                cout << "Enter 5 to get the front element" << endl;
                cout << "Enter 6 to get the last element" << endl;
                cout << "Enter any other key to exit loop" << endl;
                cout << endl;
                cin >> n;
                if (n == 1)
                {
                    cin >> val;
                    q->push_front(val);
                }
                else if (n == 2)
                {
                    cin >> val;
                    q->push_back(val);
                }
                else if (n == 3)
                {
                    q->pop_front();
                }
                else if (n == 4)
                {
                    q->pop_back();
                }
                else if (n == 5)
                {
                    int front = q->front();
                    cout << front << endl;
                }
                else if (n == 6)
                {
                    int last = q->back();
                    cout << last << endl;
                }
                else
                    break;
            }
        }
        else break;
    }
}