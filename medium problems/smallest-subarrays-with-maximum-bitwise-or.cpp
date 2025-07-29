//https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/submissions/1716162535/?envType=daily-question&envId=2025-07-29

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>bits(31,-1);
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            int endidx=i;
            int numb=nums[i];
            for(int k=0;k<=30;k++){
                if((numb & (1<<k))!=0)bits[k]=i;
                else endidx=max(endidx,bits[k]);
            }
            ans.push_back(endidx-i+1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};