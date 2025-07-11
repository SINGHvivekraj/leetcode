// https://leetcode.com/problems/find-lucky-integer-in-an-array/?envType=daily-question&envId=2025-07-05

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int ele:arr){
            mp[ele]++;
        }
        int ans=-1;
        for(auto p:mp){
            if(p.second==p.first){
                ans=max(ans,p.first);
            }
        }
        return ans;

    }
};