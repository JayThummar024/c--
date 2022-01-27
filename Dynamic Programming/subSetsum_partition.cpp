#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
bool subsetSum(vector<int>& nums, int sum, int i = 0) {
    if(sum == 0) return true;
    if(i >= nums.size() || sum < 0) return false; 
    if(dp[sum] != -1) return dp[sum];
    return dp[sum] = subsetSum(nums, sum - nums[i], i + 1) || subsetSum(nums, sum, i + 1);
}

int main(){
    vector<int> nums{100,5,11,5};
    int totalSum = accumulate(begin(nums), end(nums), 0);
    dp.resize(totalSum, -1);
    if(totalSum & 1){
        cout << 0;
        return 0;
    } 
    cout<< subsetSum(nums, totalSum / 2);
    return 0;
}