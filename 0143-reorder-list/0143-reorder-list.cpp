class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next) return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;

        ListNode *p = mid, *q = mid->next, *pp = NULL, *qq = NULL;
        mid->next = NULL;
        while (q) {
            pp = p;
            p = q;
            q = q->next;
            p->next = pp;
        }
        mid = p;

        p = head;
        q = mid;
        while (q) {
            pp = p; qq = q;
            p = p->next; q = q->next;
            pp->next = qq; qq->next = p;
        }
    }
};