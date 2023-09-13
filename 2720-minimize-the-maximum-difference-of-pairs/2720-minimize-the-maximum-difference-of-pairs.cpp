class Solution {
public:
    int ispossible(vector<int>& nums, int diff, int p) {
        int n = nums.size();
        int count=0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= diff) {
                count++;
                i++;  
            }
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int s = 0, e = nums.back() - nums.front();
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (ispossible(nums, mid, p)>=p) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};