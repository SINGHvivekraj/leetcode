//https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n=nums.size();
       int cand1=1e9+2,cand2=1e9+2,c1=0,c2=0;
       for(int ele:nums){
        if(ele==cand1)c1++;
        else if(ele==cand2)c2++;
        else if(c1==0){
            c1=1;
            cand1=ele;
        }
        else if(c2==0){
            c2=1;
            cand2=ele;
        }
        else{
            c1--;c2--;
        }
       }
       //verification if really the candidates are majority elments or not
       int f1=0,f2=0;
       for(int ele:nums){
        if(ele==cand1)f1++;
        if(ele==cand2)f2++;
       }
       vector<int>ans;
       int count=n/3;
       if(f1>count)ans.push_back(cand1);
       if(f2>count)ans.push_back(cand2);
       return ans; 
    }
};