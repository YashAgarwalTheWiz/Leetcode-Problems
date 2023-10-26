class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j, vector<vector<int>>& memo) {
        if (i == s1.size() && j == s2.size()) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        bool x = false, y = false;

        if (i != s1.size() && s1[i] == s3[i + j]) {
            x = solve(s1, s2, s3, i + 1, j, memo);
        }

        if (j != s2.size() && s2[j] == s3[i + j]) {
            y = solve(s1, s2, s3, i, j + 1, memo);
        }

        return memo[i][j] = (x || y);
    }

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int s3_len = s3.size();

        if (m + n != s3_len) {
            return false;
        }

        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

        return solve(s1, s2, s3, 0, 0, memo);
    }
};
