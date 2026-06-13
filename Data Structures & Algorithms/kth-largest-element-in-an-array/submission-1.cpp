class Solution {
public:
    //Quickselect Method
    /*int findKthLargest(vector<int>& nums, int k) {
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
    }*/

    //Min Heap Method
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> h;

        for(int i=0;i<nums.size();i++) {
            if(i<k) {
                h.push(nums[i]);
            }
            else {
                if(nums[i]>h.top()) {
                    h.pop();
                    h.push(nums[i]);
                }
            }
        }

        return h.top();
    }
};