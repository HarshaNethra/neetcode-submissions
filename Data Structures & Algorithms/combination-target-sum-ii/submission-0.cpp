class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        sort(candidates.begin(), candidates.end());

        genCS(candidates, target, 0, current);
        return ans;
    }

    void genCS(vector<int> &candidates, int target, int idx, vector<int> &current){
        if(target==0) {
            ans.push_back(current);
            return;
        }

        if(idx==candidates.size() || target<0)
            return;
        

        current.push_back(candidates[idx]);
        genCS(candidates, target-candidates[idx], idx+1, current);
        current.pop_back();

        int ele=candidates[idx];
        while(idx<candidates.size() && candidates[idx]==ele)
            idx++;
        genCS(candidates, target, idx, current);
    }
};
