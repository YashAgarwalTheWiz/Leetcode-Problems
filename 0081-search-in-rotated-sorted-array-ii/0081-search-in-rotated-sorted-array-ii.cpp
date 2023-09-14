
    class Solution {
public:
    bool searchUtil(vector<int>& nums, int low, int high, int target) {
        if (low > high) {
            return false;
        }
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) {
            return true;
        }
        
        if (nums[low] == nums[mid] && nums[high] == nums[mid]) {
            low++;
            high--;
            return searchUtil(nums, low, high, target);
        }
        
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target <= nums[mid]) {
                return searchUtil(nums, low, mid - 1, target);
            } else {
                return searchUtil(nums, mid + 1, high, target);
            }
        }
        
        if (target >= nums[mid] && target <= nums[high]) {
            return searchUtil(nums, mid + 1, high, target);
        }
        
        return searchUtil(nums, low, mid - 1, target);
    }
    
    bool search(vector<int>& nums, int target) {
        return searchUtil(nums, 0, nums.size() - 1, target);
    }
};