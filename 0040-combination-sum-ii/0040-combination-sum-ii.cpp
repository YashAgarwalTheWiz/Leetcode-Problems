class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& candi, int target, int index, int sum) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < candi.size(); i++) {
            // Skip duplicates
            if (i > index && candi[i] == candi[i - 1]) {
                continue;
            }
            if (sum + candi[i] <= target) { // Add this condition
                temp.push_back(candi[i]);
                solve(ans, temp, candi, target, i + 1, sum + candi[i]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candi.begin(), candi.end());
        solve(ans, temp, candi, target, 0, 0);
        return ans;
    }
};
