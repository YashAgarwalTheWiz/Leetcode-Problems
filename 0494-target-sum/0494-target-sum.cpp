class Solution {
public:
    int solve(int index, int sum, int target, vector<int>& nums) {
        if (index == nums.size()) {
            return (sum == target) ? 1 : 0;
        }

        int add = solve(index + 1, sum + nums[index], target, nums);
        int sub = solve(index + 1, sum - nums[index], target, nums);
        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, target, nums);
    }
};
