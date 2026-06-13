class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> h;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++) {
            if(i<k) h.push(nums[i]);
            else {
                if(nums[i]>h.top()) {
                    h.pop();
                    h.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(h.size()<k) h.push(val);
        else if(val>h.top()) {
            h.pop();
            h.push(val);
        }

        return h.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */