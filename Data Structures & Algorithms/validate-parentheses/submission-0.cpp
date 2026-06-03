class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for (int i=0;s[i]!='\0';i++) {
            if ((s[i]=='(' || s[i]=='{' || s[i]=='[')) {
                str.push(s[i]);
            }
            else if (!str.empty()) {
                if (str.top()=='(' && s[i]==')') {
                    str.pop();
                }
                else if (str.top()=='{' && s[i]=='}') {
                    str.pop();
                }
                else if (str.top()=='[' && s[i]==']') {
                    str.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return str.empty();
    }
};