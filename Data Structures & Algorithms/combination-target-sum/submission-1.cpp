class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        dfs(candidates, current, 0, target);
        return ans;
    }

    void dfs(vector<int> &candidates, vector<int> &current, int index, int remaining) {
        if(remaining==0) {
            ans.push_back(current);
            return;
        }

        if(index==candidates.size()) return;
        
        if(remaining<0) return;

        current.push_back(candidates[index]);
        dfs(candidates, current, index, remaining-candidates[index]);

        current.pop_back();
        dfs(candidates, current, index+1, remaining);
    }
};