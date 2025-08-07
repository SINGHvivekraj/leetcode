//https://leetcode.com/problems/unique-paths-ii/
//bottom up approach with time complexity n^2

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n));
        bool flag=false;
        if(m==1 and n==1)return !grid[0][0];
        if(grid[0][0]==1 or grid[m-1][n-1]==1)return 0;
        for(int c=n-2;c>=0;c--){
            if(grid[m-1][c]==1){
                flag=true;
            }
            if(flag)dp[m-1][c]=0;
            else dp[m-1][c]=1;
        }
        flag=false;
        for(int r=m-2;r>=0;r--){
            if(grid[r][n-1]==1){
                flag=true;
            }
            if(flag)dp[r][n-1]=0;
            else dp[r][n-1]=1;
        }
        for(int r=m-2;r>=0;r--){
            for(int c=n-2;c>=0;c--){
                if(grid[r][c]==1)dp[r][c]=0;
                else{
                    dp[r][c]=dp[r+1][c]+dp[r][c+1];
                }
            }
        }
        return dp[0][0];

    }
};