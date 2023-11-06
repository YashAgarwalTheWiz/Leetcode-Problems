class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        vector<int> color(n, 0); // 0: unvisited, 1: visiting, 2: visited and safe
        vector<int> memo(n, -1); // Memoization array

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, color, memo)) {
                result.push_back(i);
            }
        }

        return result;
    }

    bool dfs(int i, vector<vector<int>>& graph, vector<int>& color, vector<int>& memo) {
        if (color[i] == 2) {
            return true; // This node is already visited and safe.
        }

        if (color[i] == 1) {
            return false; // This node is currently being visited, indicating a cycle.
        }

        if (memo[i] != -1) {
            return memo[i] == 1; // Return cached result.
        }

        color[i] = 1; // Mark as visiting

        for (int neighbor : graph[i]) {
            if (!dfs(neighbor, graph, color, memo)) {
                memo[i] = 0; // Mark as not safe
                return false;
            }
        }

        color[i] = 2; // Mark as visited and safe
        memo[i] = 1; // Mark as safe
        return true;
    }
};
