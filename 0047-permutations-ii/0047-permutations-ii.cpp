class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, vector<bool>& visit) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])) {
                continue;
            }

            visit[i] = true;
            temp.push_back(nums[i]);
            solve(ans, temp, nums, visit);
            visit[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visit(nums.size());
        sort(nums.begin(), nums.end()); 
        solve(ans, temp, nums, visit);
        return ans;
    }
};
