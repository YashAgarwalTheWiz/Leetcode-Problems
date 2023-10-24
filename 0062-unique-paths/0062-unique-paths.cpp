class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 &&  j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=0,right=0;
        if(i<m)
         down=solve(i+1,j,m,n,dp);
        if(j<n)
         right=solve(i,j+1,m,n,dp);
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp);
    }
};