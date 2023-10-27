class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int bottom = 0, up = 0, left = 0, right = 0;
        int currentVal = matrix[i][j];
        
        if (i + 1 < matrix.size() && matrix[i + 1][j] > currentVal) {
            bottom =  solve(i + 1, j, matrix, memo);
        }
        if (i - 1 >= 0 && matrix[i - 1][j] > currentVal) {
            up =  solve(i - 1, j, matrix, memo);
        }
        if (j + 1 < matrix[0].size() && matrix[i][j + 1] > currentVal) {
            right =  solve(i, j + 1, matrix, memo);
        }
        if (j - 1 >= 0 && matrix[i][j - 1] > currentVal) {
            left =  solve(i, j - 1, matrix, memo);
        }
        
        memo[i][j] = max(bottom, max(up, max(right, left))) + 1;
        return memo[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int> > memo(rows, vector<int>(cols, -1));
        
        int maxLength = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int pathLength = solve(i, j, matrix, memo);
                maxLength = max(maxLength, pathLength);
            }
        }
        
        return maxLength;
    }
};
