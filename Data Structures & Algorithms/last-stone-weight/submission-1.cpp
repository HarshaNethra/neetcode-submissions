class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> h(stones.begin(), stones.end());

        while(h.size()>1) {
            int first=h.top();
            h.pop();
            int second=h.top();
            h.pop();
            if(first==second) {
                continue;
            }
            else {
                int newWeight=abs(first-second);
                h.push(newWeight);
            }
        }
        
        return h.empty()?0:h.top();
    }
};