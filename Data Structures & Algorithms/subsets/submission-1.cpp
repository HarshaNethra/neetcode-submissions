class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        generateSubsets(nums, 0, current);
        return ans;
    }

    void generateSubsets(vector<int> &nums, int idx, vector<int> &current) {
        if(idx>=nums.size()) {
            ans.push_back(current);
            return;
        }

        current.push_back(nums[idx]);
        generateSubsets(nums, idx+1, current);
        
        current.pop_back();

        generateSubsets(nums, idx+1, current);
    }
};