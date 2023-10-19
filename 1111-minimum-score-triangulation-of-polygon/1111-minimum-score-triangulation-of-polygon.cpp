class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<int>& v,int i,int j){
        if(i+1==j)
          return 0;
          if(dp[i][j]!=-1)
             return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+ solve(dp,v,i,k)+solve(dp,v,k,j));
            dp[i][j]=ans;
        }
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(values.size(),vector<int>(values.size(),-1));
        return solve(dp,values,0,values.size()-1);
    }
};