#include <iostream>
#include "linkedlist.h"
using namespace std;

class Dequeue
{
    LinkedList* list;
    int count;
    // Implement dequeue using linked list.
    public:
    Dequeue(int val){
        list = new LinkedList(val);
        count = 0;
    };
    void push_back(int num)
    {
        list->insert_at_end(num);
        count++;
        // Insert element at the back of the dequeue.
    }
    void push_front(int num)
    {
        list->insert_at_start(num);
        count++;
        // Insert element at the front of the dequeue.
    }
    void pop_back()
    {
        list->remove_from_end();
        count--;
        // Remove the element from the back of the dequeue.
    }
    void pop_front()
    {
        list->remove_from_start();
        count--;
        // Insert element at the front of the dequeue.
    }
    int front()
    {
        if(count <= 0) return -1;
        int val = list->front();
        return val;
        // Return the front element of the queue.
    }
    int back()
    {
        if(count <= 0) return -1;
        int val = list->last();
        return val;
        // Return the back element of the queue.
    }
};