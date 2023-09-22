class Solution {
public:
    bool canPartition(vector<int>& nums, vector<int>& sides, int index, int target) {
        if (index == -1) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + nums[index] <= target) {
                sides[i] += nums[index];
                if (canPartition(nums, sides, index - 1, target)) {
                    return true;
                }
                sides[i] -= nums[index];
            }

            // Skip the same elements to avoid duplicates
            if (sides[i] == 0) {
                break;
            }
        }

        return false;
    }

    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        int target = sum / 4;

        sort(nums.rbegin(), nums.rend());

        vector<int> sides(4, 0);
        return canPartition(nums, sides, nums.size() - 1, target);
    }
};
