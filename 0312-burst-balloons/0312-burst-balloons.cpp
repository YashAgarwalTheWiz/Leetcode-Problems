class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, 0));

        return solve(1, n, nums, memo);
    }

    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& memo) {
        if (i > j)
            return 0;

        if (memo[i][j] != 0)
            return memo[i][j];

        int maxCoins = 0;
        for (int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1] + solve(i, k - 1, nums, memo) + solve(k + 1, j, nums, memo);
            maxCoins = max(maxCoins, coins);
        }

        memo[i][j] = maxCoins;
        return maxCoins;
    }
};
