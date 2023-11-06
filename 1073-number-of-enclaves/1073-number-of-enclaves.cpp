class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, int delrow[], int delcol[]) {
        grid[row][col] = 2;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, delrow, delcol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = { -1, 0, 1, 0 };
        int delcol[] = { 0, 1, 0, -1 };

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                dfs(0, j, grid, delrow, delcol);
            }
            if (grid[n - 1][j] == 1) {
                dfs(n - 1, j, grid, delrow, delcol);
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, grid, delrow, delcol);
            }
            if (grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
