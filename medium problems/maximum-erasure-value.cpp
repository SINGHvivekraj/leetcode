//https://leetcode.com/problems/maximum-erasure-value/?envType=daily-question&envId=2025-07-22

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int sidx=0;
        int currsum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find((nums[i]))==mp.end()){
                currsum+=nums[i];
                ans=max(ans,currsum);
                mp.insert({nums[i],i});
            }
            else{
                int idx=mp[nums[i]];
                for(int j=sidx;j<=idx;j++){
                    mp.erase(nums[j]);
                    currsum-=nums[j];
                }
                currsum+=nums[i];
                ans=max(ans,currsum);
                mp.insert({nums[i],i});
                sidx=idx+1;

            }
        }
        return ans;
    }
};