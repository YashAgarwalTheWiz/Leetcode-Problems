class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>>& memo) {
        if (amount == 0) {
            return 1;
        }
        if (index == coins.size() || amount < 0) {
            return 0;
        }

        if (memo[index][amount] != -1) {
            return memo[index][amount];
        }

        int include = solve(index, amount - coins[index], coins, memo);
        int exclude = solve(index + 1, amount, coins, memo);

        memo[index][amount] = include + exclude;
        return memo[index][amount];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return solve(0, amount, coins, memo);
    }
};
