class Solution {
public:
    bool fun(vector<int>& piles, int cap, int h) {
        for (int i = 0; i < piles.size(); i++) {
            h -= (piles[i] + cap - 1) / cap;
        }
        return h >= 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = *max_element(piles.begin(), piles.end());
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (fun(piles, mid, h)) {
                e = mid - 1;
            } else {
                s = mid + 1;  
            }
        }
        
        return s;
    }
};
