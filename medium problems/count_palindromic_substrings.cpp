//https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    int countSubstrings(string s) {
      int n=s.size();
      int count=0;
      vector<vector<bool>>dp(n,vector<bool>(n,false));
      for(int l=1;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j=i+l-1;
            if(j==i){
                dp[i][j]=true;
                count++;
            }
            else if(j==(i+1) and s[i]==s[j]){
                dp[i][j]=true;
                count++;
            }
            else if(s[i]==s[j] and dp[i+1][j-1]){
                dp[i][j]=true;
                count++;
            }
        }
      } 
      return count;
    }
};