#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> v(20001);
    for(int i=0; i<n; i++){
        v[nums[i] + 10000]++;
    }
    int curr = 0;
    for(int i=20000; i>=0 && k>0; i--){
        if(v[i] > 0) {
            curr = i-10000;
            k -= v[i];
        }
    }
    return curr;
}

int main(){
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int ans = findKthLargest(v, k);
}