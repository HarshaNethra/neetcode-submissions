class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string paran;
        for(int i=0;i<2*n;i++) {
            if(i<n) {
                paran+='(';
            }
            else
                paran+=')';
        }

        unordered_set<string> ans;
        genPerm(paran, 0, ans);
        
        vector<string> result(ans.begin(), ans.end());
        return result;
    }

    void genPerm(string paran, int idx, unordered_set<string> &ans) {
        if(idx==paran.size()) {
            int check=0;
            for(int i=0;i<paran.size();i++) {
                if(paran[i]=='(')
                    check++;
                else
                    check--;
                
                if(check<0)
                    return;
            }

            if(check!=0 || paran[0]!='(' || paran[idx-1]!=')')
                return;
            ans.insert(paran);
        }

        unordered_set<int> exchanged;
        for(int i=idx;i<paran.size();i++) {
            if (exchanged.count(paran[i])) continue;
            exchanged.insert(paran[i]);

            swap(paran[idx], paran[i]);
            genPerm(paran, idx+1, ans);
            swap(paran[idx], paran[i]);
        }
    }
};
