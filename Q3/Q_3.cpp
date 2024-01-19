#include <iostream>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n=nums.size();
    int v[n][n];
    int sum = 0;
    sort(nums.begin(), nums.end());
    int less = 0, more = 0;
    int temp = abs(nums[2] - (target - (nums[0]+nums[1])));
    int achieved = nums[0] + nums[1] + nums[2];
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(i!=j) {
                v[i][j] = target - (nums[i]+nums[j]);
                int index = lower_bound(nums.begin(), nums.end(), v[i][j]) - nums.begin();
                less = index--; more = index++;
                if(index == n) index--;
                while(less >= 0 && (less == i || less == j)) less--;
                while(more < n && (less == i || less == j)) more++;
                if(index != i && index != j && index>=0 && index < n) {
                    if(abs(nums[index]-v[i][j]) < temp){
                        temp = abs(nums[index]-v[i][j]);
                        if(nums[index]>v[i][j]) achieved = target+temp;
                        else achieved = target-temp;
                    }
                }
                if(less != i && less != j && less>=0 && less<n) {
                    if(abs(nums[less]-v[i][j]) < temp){
                        temp = abs(nums[less]-v[i][j]);
                        if(nums[less]>v[i][j]) achieved = target+temp;
                        else achieved = target-temp;
                    }
                }
                if(more != i && more != j && more < n && more>=0) {
                    if(abs(nums[more]-v[i][j]) < temp){
                        temp = abs(nums[more]-v[i][j]);
                        if(nums[more]>v[i][j]) achieved = target+temp;
                        else achieved = target-temp;
                    }
                }
            }
        }
    }
    return achieved;
}   

int main(){
    int n; cin>>n;
    ve
}
