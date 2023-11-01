class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newcolor, int ini) {
        int n = image.size();
        int m = image[0].size();
        
        if (row < 0 || row >= n || col < 0 || col >= m) {
            return;
        }

        if (image[row][col] == ini && ans[row][col] != newcolor) {
            ans[row][col] = newcolor;
            
           
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                dfs(nrow, ncol, ans, image, newcolor, ini);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int inicolor = image[sr][sc];
        if (inicolor == newColor) {
            return image; 
        }
        
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, newColor, inicolor);
        return ans;
    }
};
