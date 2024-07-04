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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* ans = head;
        int sum = 0;
        while(temp != NULL){
            sum += temp->val;
            if(temp->next->val == 0){
                temp->next->val = sum;
                head->next = temp->next;
                head = head->next;
                sum = 0;
                temp = temp->next;
            }
            temp = temp->next;
        }

        return ans->next;
    }
};