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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode* t1 = head;
        ListNode* t2 = t1->next;
        while(t2)
        {
            ListNode* a = new ListNode(gcd(t1->val , t2->val));
            t1->next = a;
            a->next = t2;
            t1 = t2;
            t2 = t2->next;
        }
        return head;
    }
};