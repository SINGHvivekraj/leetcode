//https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/submissions/1699837227/?envType=daily-question&envId=2025-07-16

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int evencount=0;
        bool isEven=nums[0]%2==0;
        if(isEven)evencount++;
        int altercount=1;
        for(int i=1;i<n;i++){
            if((nums[i]%2==0)!=isEven){
                altercount++;
                isEven=!isEven;
            }
            if(nums[i]%2==0)evencount++;
        }
        return max({altercount,evencount,n-evencount});

    }
};