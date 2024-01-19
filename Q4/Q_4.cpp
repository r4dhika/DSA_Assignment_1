#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<int> v = nums;
    vector<int> s(n);
    s[0] = v[0];
    int possible = true;
    for(int i=1; i<n && possible; i++){
        if(s[i-1] > 0) s[i] = max(s[i-1]-1, v[i]);
        else possible = false;
    }
    if(possible) return true;
    else return false;
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    bool ans = canJump(v);
    cout<<ans<<endl;
}