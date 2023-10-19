class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, vector<int>& memo, int index) {
        if (index >= days.size()) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int day1 = costs[0] + solve(days, costs, memo, index + 1);
        int i;
        for (i = index; i < days.size() && days[i] < days[index] + 7; i++);
        int day7 = costs[1] + solve(days, costs, memo, i);
        for (i = index; i < days.size() && days[i] < days[index] + 30; i++);
        int day30 = costs[2] + solve(days, costs, memo, i);

        int minCost = min(day1, min(day7, day30));
        memo[index] = minCost;
        return minCost;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1);
        return solve(days, costs, memo, 0);
    }
};
