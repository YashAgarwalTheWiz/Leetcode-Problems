class Solution {
public:
    long long mod = 1000000007;
    long long helper(vector<vector<long long>>& dp, int steps, int arrLen, int i) {
        if (i < 0 || i >= arrLen) {
            return 0;
        }
        if (steps == 0) {
            return (i == 0) ? 1 : 0;
        }
        if (dp[steps][i] != -1) {
            return dp[steps][i];
        }
        long long ways = (
            helper(dp, steps - 1, arrLen, i - 1) +
            helper(dp, steps - 1, arrLen, i) +
            helper(dp, steps - 1, arrLen, i + 1)
        ) % mod;
        dp[steps][i] = ways;
        return ways;
    }

    int numWays(int steps, int arrLen) {
        int maxArrLen = min(steps, arrLen);
        vector<vector<long long>> dp(steps + 1, vector<long long>(maxArrLen, -1));
        return static_cast<int>(helper(dp, steps, maxArrLen, 0));
    }
};
