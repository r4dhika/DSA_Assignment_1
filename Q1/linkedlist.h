#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val){
        value = val;
    }
};

class LinkedList
{
    Node* head;
    Node* tail;
    // Implement singly linked list with following functions.
public:
    LinkedList(int val){
        head = new Node(val);
        tail = head;
    };
    void insert_at_start(int num)
    {
        if(head == nullptr){
            head = new Node(num);
            tail = head;
            return;
        }
        // Insert the element at the start of the list.
        Node* newnode = new Node(num);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    void remove_from_start()
    {
        // Remove the element from the start of the list.
        if(head == nullptr) return; 
        Node* temp = head->next;
        Node* temp2 = head;
        delete temp2;

        if(head == tail){
            tail = nullptr;
            head = nullptr;
            return;
        }
        head = temp;
    }
    void insert_at_end(int num)
    {
        if(head == nullptr){
            head = new Node(num);
            tail = head;
            return;
        }
        // Insert the element at the end of the list.
        Node* newnode = new Node(num);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    void remove_from_end()
    {
        if(head == nullptr) return;
        Node* temp = tail->prev;
        Node* temp2 = tail;
        delete temp2;
        // Remove the element from the end of the list.
        if(head == tail){
            tail = nullptr;
            head = nullptr;
            return;
        }
        tail = temp;
        tail->next = nullptr;
    }
    int front()
    {
        // Return the first element of the list.
        if(head == nullptr) return -1;
        return head->value;
    }
    int last()
    {
        // Return the last element of the list.
        if(head == nullptr) return -1;
        return tail->value;
    }
    void traverse()
    {
        // Print all the elements from start to the end of the list.
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};