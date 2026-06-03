class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*int last=nums.size();
        int first=0;
        while(first<last) {
            if(nums[first]==val) {
                swap(nums[first], nums[last-1]);
                last--;
            }
            else {
                first++;
            }
        }

        return first;*/


        // Alternative
        int k=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=val)
                nums[k++]=nums[i];
        }

        return k;
    }
};