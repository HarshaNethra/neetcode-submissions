class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low=0, high=nums.size()-1;
        while(low<=high) {
            int pivot=nums[high];
            int left=low;
            for(int i=low;i<high;i++) {
                if(nums[i]>pivot) {
                    swap(nums[left++], nums[i]);
                }
            }
            swap(nums[left], nums[high]);

            if(left==k-1)
                return nums[left];
            else if(left<k-1) {
                low=left+1;
            }
            else {
                high=left-1;
            }
        }

        return -1;
    }
};