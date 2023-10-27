class Solution {
public:
    int solve(int indext, int indexs, string t, string s, vector<vector<int>>& dp) {
        if (indext == t.size()) {
            return 1;
        }
        if (indexs == s.size()) {
            return 0;
        }
        if (dp[indext][indexs] != -1) {
            return dp[indext][indexs];
        }

        int take = 0, nottake = 0;

        if (s[indexs] == t[indext]) {
            take = solve(indext + 1, indexs + 1, t, s, dp);
        }
        nottake = solve(indext, indexs + 1, t, s, dp);

        return dp[indext][indexs] = take + nottake;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, -1));
        return solve(0, 0, t, s, dp);
    }
};
