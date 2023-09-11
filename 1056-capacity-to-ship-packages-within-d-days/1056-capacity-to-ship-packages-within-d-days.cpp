class Solution {
public:
    int fun(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                load = weights[i];
                days++;
            } else {
                load += weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); 
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = (low + high) / 2;
            int rdays = fun(weights, mid);

            if (rdays > days) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
