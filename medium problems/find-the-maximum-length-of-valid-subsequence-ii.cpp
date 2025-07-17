//https: // leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/submissions/1701393902/?envType=daily-question&envId=2025-07-17


class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(k,vector<int>(n,1));
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int modval=(nums[i]+nums[j])%k;
                dp[modval][i]=max(dp[modval][i],dp[modval][j]+1);
                ans=max(ans,dp[modval][i]);
            }
        }
        return ans;

    }
};