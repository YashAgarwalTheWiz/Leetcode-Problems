class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int x, int y, int index) {
        if (index == word.length()) {
            return true;
        }

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]) {
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '*';

        bool found = (helper(board, word, x - 1, y, index + 1) ||
                      helper(board, word, x + 1, y, index + 1) ||
                      helper(board, word, x, y - 1, index + 1) ||
                      helper(board, word, x, y + 1, index + 1));
        board[x][y] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if (m == 0 || n == 0) {
            return false;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (helper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
