class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> current;
        genPal(s, current, 0);
        return ans;
    }

    void genPal(string &s, vector<string> &current, int idx) {
        if (idx==s.size()) {
            ans.push_back(current);
        }

        for (int i=idx; i<s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                current.push_back(s.substr(idx, i-idx+1));
                genPal(s, current, i+1);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int start, int end) {
        int i=start, j=end;
        while(i<j) {
            if (s[i]!=s[j])
                return false;
            i++;j--;
        }

        return true;
    }
};