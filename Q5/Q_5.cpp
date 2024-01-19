#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
public:

    deque<int> q1;
    deque<int> q2;
    int first = 0;
    int second = 0;

    FrontMiddleBackQueue() {
        deque<int> q1;
        deque<int> q2;
        int first = 0;
        int second = 0;
    }

    void pushFront(int val) {
        q1.push_front(val);
        first++;
        if(first > second) {
            int temp = q1.back();
            q1.pop_back();
            q2.push_front(temp);
            first--;
            second++;
        }
        return;
    }
    
    void pushMiddle(int val) {
        if(first == second) {
            q2.push_front(val);
            second++;
        }
        else if(first<second){
            q1.push_back(val);
            first++;
        }
        // cout<<first<<" "<<second<<endl;
        return;
    }
    
    void pushBack(int val) {
        // cout<<first<<" "<<second<<" "<<val<<endl;
        if(first == second){
            q2.push_back(val);
            second++;
        }
        else if(first<second){
            q2.push_back(val);
            int temp = q2.front();
            q2.pop_front();
            q1.push_back(temp);
            first++;
        }
        // cout<<first<<" "<<second<<" "<<val<<q2.front()<<endl;
        return;
    }
    
    int popFront() {
        if(first == second && first != 0){
            int val = q1.front();
            q1.pop_front();
            first--;
            return val;
        }
        else if(first == 0 && second == 1){
            int val = q2.front();
            q2.pop_front();
            second--;
            return val;
        }
        else if(first<second){
            int val = q1.front();
            q1.pop_front();
            int temp = q2.front();
            q2.pop_front();
            q1.push_back(temp);
            second--;
            return val;
        }
        else return -1;
    }
    
    int popMiddle() {
        // cout<<first<<" "<<second<<endl;
        if(first == second && first != 0){
            int val = q1.back();
            q1.pop_back();
            first--;
            return val;
        }
        else if(first < second){
            int val = q2.front();
            q2.pop_front();
            second--;
            return val;
        }
        else return -1;
    }
    
    int popBack() {
        if(first == second && first != 0){
            int val = q2.back();
            q2.pop_back();
            int temp = q1.back();
            q1.pop_back();
            q2.push_front(temp);
            first--;
            return val;
        }
        else if(first < second){
            int val = q2.back();
            q2.pop_back();
            second--;
            return val;
        }
        else return -1;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */