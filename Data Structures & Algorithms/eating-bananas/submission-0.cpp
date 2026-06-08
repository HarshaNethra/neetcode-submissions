class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=*max_element(piles.begin(), piles.end());
        int k=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(validateSpeed(mid, piles, h)) {
                k=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }

        return k;
    }

    bool validateSpeed(int s, vector<int> &piles, int h) {
        long long hours=0;
        for(int pile:piles) {
            hours+=(pile+s-1)/s;
        }

        if(hours<=h) return true;
        return false;
    }
};
