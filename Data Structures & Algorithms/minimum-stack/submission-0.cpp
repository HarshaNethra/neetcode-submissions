class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty() && mins.empty()) {
            mins.push(val);
        }
        else {
            if(val<=mins.top()) {
                mins.push(val);
            }
        }

        s.push(val);
    }
    
    void pop() {
        int x=s.top();
        s.pop();

        if(x==mins.top())
            mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};