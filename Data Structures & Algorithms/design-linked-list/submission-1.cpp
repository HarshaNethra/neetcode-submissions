class MyLinkedList {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int val): val(val), next(NULL) {};
    };
public:
    ListNode *head;
    int size;
    
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index>=size) return -1;
        ListNode *trav=head;
        while(index>0) {
            trav=trav->next;
            index--;
        }

        return trav->val;
    }
    
    void addAtHead(int val) {
        ListNode *node=new ListNode(val);
        node->next=head;
        head=node;
        size++;
    }
    
    void addAtTail(int val) {
        if(!head) {
            head=new ListNode(val);
            head->next=NULL;
            size++;
            return;
        }

        ListNode *trav=head;
        while(trav->next!=NULL) {
            trav=trav->next;
        }

        trav->next=new ListNode(val);
        trav->next->next=NULL;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        if(index==0) addAtHead(val);
        else if(index==size) addAtTail(val);
        else {
            ListNode *trav=head;
            while(index>1) {
                trav=trav->next;
                index--;
            }

            ListNode *temp=trav->next;
            trav->next=new ListNode(val);
            trav->next->next=temp;

            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(size==0 || index>=size) return;
        if(size==1) {
            delete head;
            head=NULL;
            size--;
            return;
        }
        if(index==0) {
            ListNode *temp=head;
            head=head->next;
            delete temp;
            size--;
            return;
        }
        ListNode *trav=head;
        while(index>1) {
            trav=trav->next;
            index--;
        }
        ListNode *temp=trav->next;
        trav->next=trav->next->next;
        delete temp;

        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */