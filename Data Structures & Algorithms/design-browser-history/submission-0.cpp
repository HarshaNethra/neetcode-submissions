class BrowserHistory {
    struct ListNode {
        string url;
        ListNode *pre;
        ListNode *next;
        ListNode(string url): url(url), pre(NULL), next(NULL) {};
    };
public:
    ListNode *head;
    ListNode *current;
    BrowserHistory(string homepage) {
        head=new ListNode(homepage);
        current=head;
    }
    
    void visit(string url) {
        if(current->next!=NULL) {
            ListNode *trav=current->next;
            ListNode *temp;
            while(trav!=NULL) {
                temp=trav;
                trav=trav->next;
                delete temp;
            }
        }
        current->next=NULL;
        current->next=new ListNode(url);
        current->next->pre=current;
        current=current->next;
    }
    
    string back(int steps) {
        while(current->pre!=NULL && steps>0) {
            current=current->pre;
            steps--;
        }

        return current->url;
    }
    
    string forward(int steps) {
        while(current->next!=NULL && steps>0) {
            current=current->next;
            steps--;
        }

        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */