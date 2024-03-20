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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list2;
        while(temp->next){
            temp=temp->next;
        }
        temp=temp->next;

        ListNode* temp2=list1;
        ListNode* temp3=list1;

        while(a>1 || b>0){
            if(a>1){
                temp2=temp2->next;
                a--;
            }
            if(b>0){
                temp3=temp3->next;
                b--;
            }
        }

        temp2->next=list2;
        cout<<temp3->val;
        ListNode* temp4=list1;
        while(temp4->next!=NULL){
            temp4=temp4->next;
        }
        temp4->next=temp3->next;
        temp3=NULL;

        return list1;
    }
};