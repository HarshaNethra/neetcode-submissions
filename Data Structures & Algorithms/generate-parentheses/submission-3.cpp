class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string current="";
        genPerm(current, 0, 0, n);
        
        return ans;
    }

    void genPerm(string &current, int open, int close, int n) {
        if(current.size()==2*n) {
            ans.push_back(current);
            return;
        }

        if(open<n) {
            current+='(';
            genPerm(current, open+1, close, n);
            current.pop_back();
        }

        if(close<open) {
            current+=')';
            genPerm(current, open, close+1, n);
            current.pop_back();
        }
    }
};
