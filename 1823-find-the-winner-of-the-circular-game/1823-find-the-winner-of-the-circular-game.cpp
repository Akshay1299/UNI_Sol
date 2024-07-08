class node {
public:
    int val;
    node* next;
    node(int n){
        val = n;
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        node* head = new node(1);
        head->next = head;
        node* ptr = head;
        for(int i=2; i<=n; i++){
            node* newnode = new node(i);
            ptr->next = newnode;
            newnode->next = head;
            ptr = newnode;
        }
        node* prev = ptr;
        while(head->next!=head){
            for(int i=1; i<k; i++){
                head = head->next;
                prev = prev->next;
            }
            prev->next = head->next;
            node* t = head;
            head = head->next;
            delete t;
        }
        return prev->val;
    }
};