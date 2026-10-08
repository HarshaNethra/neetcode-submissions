class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        generateCS(candidates, target, 0, current);
        return ans;
    }

    void generateCS(vector<int> &candidates, int target, int idx, vector<int> &current) {
        
        if(target==0) {
            ans.push_back(current);
            return;
        }
        if(idx>=candidates.size())
            return;
        if(target<0)
            return;
        
        current.push_back(candidates[idx]);
        generateCS(candidates, target-candidates[idx], idx, current);
        
        current.pop_back();

        generateCS(candidates, target, idx+1, current);
    }
};