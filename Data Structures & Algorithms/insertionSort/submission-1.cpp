// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> ans;

        if(pairs.size()==0)
            return {};

        int j=0;
        for(int i=1;i<pairs.size();i++) {
            ans.push_back(pairs);
            j=i-1;
            while(j>=0 && pairs[j+1].key<pairs[j].key) {
                swap(pairs[j+1],pairs[j]);
                j--;
            }
        }
        ans.push_back(pairs);
        
        return ans;
    }
};