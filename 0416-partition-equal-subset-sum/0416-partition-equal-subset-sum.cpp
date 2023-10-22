class Solution {
public:
    bool solve(vector<int>&nums,int index,int target,vector<vector<int>>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(target<0)
           return 0;
        if (target==0)
           return 1;
        if(dp[index][target]!=-1)
           return dp[index][target];
        bool incl=solve(nums,index+1,target-nums[index],dp);
        bool excl=solve(nums,index+1,target,dp);
        return dp[index][target]=(incl||excl);
    }
    bool canPartition(vector<int>& nums) {
        
        int tar=accumulate(nums.begin(),nums.end(),0);
        if(tar&1==1){
            return false;
        }
        int target=tar/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        return solve(nums,0,target,dp);
    }
};