//https://leetcode.com/problems/maximum-alternating-subsequence-sum/

class Solution {
public:
    vector<vector<long long>>dp;
    long long solve(int i,vector<int>&nums,bool isPos){
        if(i>=nums.size())return 0;
        if(dp[i][isPos]!=-1)return dp[i][isPos];
        long long take=((isPos)?nums[i]:-nums[i])+solve(i+1,nums,!isPos);
        long long skip=solve(i+1,nums,isPos);
        return dp[i][isPos]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<long long>(2,-1));
        return solve(0,nums,true);
    }
};