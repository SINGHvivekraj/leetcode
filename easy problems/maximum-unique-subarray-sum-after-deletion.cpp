//https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/submissions/1711151552/?envType=daily-question&envId=2025-07-25

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0,mx=-200;
        for (int& ele : nums) {
            if (ele > 0 and !s.count(ele)) {
                s.insert(ele);
                ans += ele;
            }
            else if(ele<=0)mx=max(mx,ele);
        }
        return ans==0?mx:ans;
    }
};