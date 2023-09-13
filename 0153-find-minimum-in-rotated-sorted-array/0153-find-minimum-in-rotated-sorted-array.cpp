class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(true){
            int mid=(s+e)/2;
            if(nums[mid]>nums[s] && nums[mid]>nums[e] )
                s=mid+1;
            else if(nums[mid]<nums[s] && nums[mid]<nums[e] )
                e=mid;
            else if(nums[s]>nums[e])
                return nums[e];
            else
                return nums[s];
            
            }
        return -1;
        
        
    }
};