//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
      int n=s.size();
      int si=0,len=1;
      vector<vector<bool>>dp(n,vector<bool>(n,false));
      for(int l=1;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j=i+l-1;
            if(j==i)dp[i][j]=true;
            else if(j==(i+1) and s[i]==s[j]){
                dp[i][j]=true;
                if((j-i+1)>len){
                    len=2;
                    si=i;
                }
            }
            else if(s[i]==s[j] and dp[i+1][j-1]){
                dp[i][j]=true;
                if((j-i+1)>len){
                    len=(j-i+1);
                    si=i;
                }
            }
        }
      } 
      return s.substr(si,len); 
    }
};