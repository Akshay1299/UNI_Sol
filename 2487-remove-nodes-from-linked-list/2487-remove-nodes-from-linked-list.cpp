/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* rec(ListNode* head,int &mx){
        if(head==NULL) return NULL;
        
        ListNode *t=rec(head->next,mx);
        mx=max(mx,head->val);
        if(head->val<mx) return t;
        head->next=t;
        return head;
    }
    
    ListNode* removeNodes(ListNode* head) {
        int mx=0;
        return rec(head,mx);
    }
};