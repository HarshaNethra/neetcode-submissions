class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxSeen=-1;
        
        for(int i=arr.size()-1;i>=0;i--) {
            int curr=arr[i];
            arr[i]=maxSeen;
            maxSeen=max(maxSeen, curr);
        }

        return arr;
    }
};