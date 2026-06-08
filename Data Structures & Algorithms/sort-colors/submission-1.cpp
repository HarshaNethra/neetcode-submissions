class Solution {
public:
    // Counting Sort
    /*void sortColors(vector<int>& nums) {
        vector<int> count(3,0);
        for(int val:nums) {
            count[val]++;
        }

        int index=0;
        for(int i=0;i<count.size();i++) {
            while(count[i]>0) {
                nums[index++]=i;
                count[i]--;
            }
        }
    }*/

    // DNF Algorithm
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high) {
            if(nums[mid]==0) {
                swap(nums[low++], nums[mid++]);
            }
            else if(nums[mid]==1) mid++;
            else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};