class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int iniColor = image[sr][sc];

        if (iniColor == newColor) {
            return image;  // No need to perform flood fill if the colors are already the same.
        }

        vector<vector<int>> ans = image;
        stack<pair<int, int>> stk;
        stk.push({sr, sc});

        while (!stk.empty()) {
            int row = stk.top().first;
            int col = stk.top().second;
            stk.pop();

            if (ans[row][col] == iniColor) {
                ans[row][col] = newColor;

                int delrow[] = {-1, 0, 1, 0};
                int delcol[] = {0, 1, 0, -1};

                for (int i = 0; i < 4; i++) {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                        stk.push({nrow, ncol});
                    }
                }
            }
        }

        return ans;
    }
};
