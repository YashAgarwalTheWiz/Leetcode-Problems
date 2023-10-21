class Solution {
public:
    int solve(vector<int>& obstacle, int currlane, int currpos, vector<vector<int>>& dp) {
        int n = obstacle.size();
        if (currpos == n-1 ) {
            return 0;
        }
        if (dp[currlane][currpos] != -1) {
            return dp[currlane][currpos];
        }
        if (obstacle[currpos + 1] != currlane) {
            return dp[currlane][currpos] = solve(obstacle, currlane, currpos + 1, dp);
        } else {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (i != currlane && obstacle[currpos] != i) {
                    ans = min(ans, 1 + solve(obstacle, i, currpos, dp));
                }
            }
            return dp[currlane][currpos] = ans;
        }
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solve(obstacles, 2, 0, dp);
    }
};
