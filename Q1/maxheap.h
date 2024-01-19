#include<iostream>
#include<vector>
using namespace std;

class MaxHeap
{
    // Implement a max binary heap. MaxHeap();
    vector<int> heap;
    int size;
public:
    MaxHeap(){
        size = 0;
    }
    void add(int num)
    {
        heap.push_back(num);
        heapify_up(size);
        size++;
        // Add an item to heap, but make sure to preserve its heapness.
    }
    int remove_maxt()
    {
        if(size == 0) return -1;
        int max = heap[0];
        heap[0] = heap[size-1];
        size--;
        heapify_down(0);
        return max;
        // Returns and removes the current maximum element in heap.
    }
    int max()
    {
        if(size > 0) return heap[0];
        else return -1;
        // Returns the current maximum element in heap
    }
    void heapify_down(int index)
    {
        int leftchild = index*2 + 1;
        int rightchild = index*2 + 2;
        if(leftchild < size && rightchild < size){
            if(heap[leftchild]>=heap[rightchild] && heap[leftchild] > heap[index]){
                swap(heap[leftchild], heap[index]);
                heapify_down(leftchild);
            }
            else if(heap[rightchild]>heap[leftchild] && heap[rightchild] > heap[index]){
                swap(heap[rightchild], heap[index]);
                heapify_down(rightchild);
            }
            else return;
        }
        else if(leftchild < size){
            if(heap[leftchild] > heap[index]){
                swap(heap[leftchild], heap[index]);
                heapify_down(leftchild);
            }
            else return;
        }
        // Reorganize element at given index by pushing it down as necessary
    }
    void heapify_up(int index)
    {
        if(index == 0) return;

        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapify_up(parent);
        }
        // Reorganize element at given index by pushing it up as necessary
    }
};