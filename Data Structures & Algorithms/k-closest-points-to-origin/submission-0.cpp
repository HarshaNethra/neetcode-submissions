class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> q;

        for(int i=0;i<points.size();i++) {
            int x=points[i][0], y=points[i][1];
            int distance= (x*x)+(y*y);

            if(i<k) {
                q.push({distance, i});
            }
            else {
                if(distance<q.top()[0]) {
                    q.pop();
                    q.push({distance, i});
                }
            }
        }

        vector<vector<int>> ans;
        while(!q.empty()) {
            int index=q.top()[1];
            ans.push_back(points[index]);

            q.pop();
        }

        return ans;
    }
};