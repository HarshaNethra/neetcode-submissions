class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int s=nums.size();
        vector<int> ans(2*s,0);

        for(int i=0;i<s;i++) {
            ans[i]=nums[i];
            ans[s+i]=nums[i];
        }
        
        return ans;
    }
};