class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;

        for(string s: operations) {
            if(isdigit(s[0]) || s[0]=='-') {
                score.push(stoi(s));
            }
            else if (s[0]=='+') {
                int first=score.top(); score.pop();
                int second=score.top();
                score.push(first);
                score.push(first+second);
            }
            else if(s[0]=='D') {
                score.push(2*score.top());
            }
            else {
                score.pop();
            }
        }

        int sum=0;
        while(!score.empty()) {
            sum+=score.top();
            score.pop();
        }

        return sum;
    }
};