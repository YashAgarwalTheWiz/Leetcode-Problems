class Solution {
public:
    int solve(int index, int sum, int target, vector<int>& nums, vector<vector<int>>& memo) {
        if (index == nums.size()) {
            return (sum == target) ? 1 : 0;
        }
        if (memo[index][sum] != -1) {
            return memo[index][sum];
        }

        int add = solve(index + 1, sum + nums[index], target, nums, memo);
        int sub = solve(index + 1, sum - nums[index], target, nums, memo);
        
        return memo[index][sum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> memo(nums.size(), vector<int>(2001, -1));
        return solve(0, 1000, target + 1000, nums, memo); 
    }
};
