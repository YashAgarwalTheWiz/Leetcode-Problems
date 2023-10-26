class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>>& memo) {
        if (i == s1.size() && j == s2.size() && k == s3.size()) {
            return true;
        }

        if (memo[i][j][k] != -1) {
            return memo[i][j][k];
        }

        bool x = false, y = false;

        if (i != s1.size() && s1[i] == s3[k]) {
            x = solve(s1, s2, s3, i + 1, j, k + 1, memo);
        }

        if (j != s2.size() && s2[j] == s3[k]) {
            y = solve(s1, s2, s3, i, j + 1, k + 1, memo);
        }

        return memo[i][j][k] = (x || y);
    }

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int s3_len = s3.size();

        if (m + n != s3_len) {
            return false;
        }

        vector<vector<vector<int>>>
            memo(m + 1, vector<vector<int>>(n + 1, vector<int>(s3_len + 1, -1)));

        return solve(s1, s2, s3, 0, 0, 0, memo);
    }
};
