class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid, low=0, high=matrix.size()-1;
        int x=-1;
        while(low<=high) {
            mid=(low+high)/2;
            if(matrix[mid][0]==target)
                return true;
            else if(matrix[mid][0]<target) {
                x=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }

        if(x==-1) return false;

        int rmid, rlow=0, rhigh=matrix[x].size()-1;
        while(rlow<=rhigh) {
            rmid=(rlow+rhigh)/2;
            if(matrix[x][rmid]==target)
                return true;
            else if(matrix[x][rmid]<target)
                rlow=rmid+1;
            else
                rhigh=rmid-1;
        }

        return false;
    }
};