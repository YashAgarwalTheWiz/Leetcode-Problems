class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O') {
            return;
        }
        
        board[row][col] = 'Y'; 
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            dfs(row + delrow[i], col + delcol[i], board);
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }

        int n = board.size();
        int m = board[0].size();
        
    
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if (board[i][m - 1] == 'O') {
                dfs(i, m - 1, board);
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(0, j, board);
            }
            if (board[n - 1][j] == 'O') {
                dfs(n - 1, j, board);
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
