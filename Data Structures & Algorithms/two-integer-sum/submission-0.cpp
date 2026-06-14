class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> f;
        for(int i=0;i<nums.size();i++) {
            int comp=target-nums[i];
            if(f.count(comp)) {
                return {f[comp], i};
            }
            f[nums[i]]=i;
        }
        
        return {};
    }
};