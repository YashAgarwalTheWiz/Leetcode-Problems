class Solution {
public:
    int solve(int index, int target, vector<int>& stones, vector<vector<int>>& memo) {
        if (index == stones.size()) {
            return 0;
        }

        if (memo[index][target] != -1) {
            return memo[index][target];
        }

        int choice1 = 0, choice2 = 0;
        if (target >= stones[index]) {
            choice1 = stones[index] + solve(index + 1, target - stones[index], stones, memo);
        }
        choice2 = solve(index + 1, target, stones, memo);

        memo[index][target] = max(choice1, choice2);
        return memo[index][target];
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> memo(stones.size(), vector<int>(sum / 2 + 1, -1));
        return sum - 2 * solve(0, sum / 2, stones, memo);
    }
};
