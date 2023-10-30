class Solution {
public:
    int MOD = 1000000007;

    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(5, -1));
        return (solve(n, 0, dp) + solve(n, 1, dp) + solve(n, 2, dp) + solve(n, 3, dp) + solve(n, 4, dp)) % MOD;
    }

    long long solve(int n, int i, vector<vector<long long>>& dp) {
        if (n == 1)
            return 1;

        if (dp[n][i] != -1)
            return dp[n][i];

        long long result = 0;

        switch (i) {
            case 0:
                result = (result + solve(n - 1, 1, dp)) % MOD;
                break;
            case 1:
                result = (result + solve(n - 1, 0, dp) + solve(n - 1, 2, dp)) % MOD;
                break;
            case 2:
                result = (result + solve(n - 1, 0, dp)+ solve(n - 1, 1, dp) + solve(n - 1, 3, dp) +solve(n - 1,4 ,dp)) % MOD;
                break;
            case 3:
                result = (result + solve(n - 1, 4, dp)+solve(n - 1, 2, dp)) % MOD;
                break;
            case 4:
                result = (result + solve(n - 1, 0, dp)) % MOD;
                break;
        }

        return dp[n][i] = result;
    }
};
