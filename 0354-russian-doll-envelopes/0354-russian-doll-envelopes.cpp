class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1]; 
        else
            return a[0] < b[0];  
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }

        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        vector<int> lis;
        lis.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++) {
            if (envelopes[i][1] > lis.back()) {
                lis.push_back(envelopes[i][1]);
            } else {
                int it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
                lis[it] = envelopes[i][1];
            }
        }

        return lis.size();
    }
};
