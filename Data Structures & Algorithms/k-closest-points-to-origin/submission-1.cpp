class Solution {
public:
    /*vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
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
    }*/

    // Quick Select Method
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int low=0, high=points.size()-1;
        
        while(low<=high) {
            int pivot=high;
            int pivotdist=points[high][0]*points[high][0] + points[high][1]*points[high][1];
            int left=low;
            for(int i=low;i<high;i++) {
                int x=points[i][0], y=points[i][1];
                int dist=x*x + y*y;
                if(dist<pivotdist)
                    swap(points[left++], points[i]);
            }
            swap(points[left], points[pivot]);

            if(left==k-1)
                return vector<vector<int>>(points.begin(), points.begin()+k);
            else if(left<k-1)
                low=left+1;
            else
                high=left-1;
        }
        return {};
    }
};