class Solution {
public:
    void sortColors(vector<int>& nums) {
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
    }
};