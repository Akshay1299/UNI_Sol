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
  ListNode *doubleIt(ListNode *head) {
    if (head->val > 4) {
      head = new ListNode(0, head);
    }
    ListNode *current = head;
    while (current->next) {
      int mul = (current->val * 2) % 10;
      if (current->next->val > 4) {
        mul++;
      }
      current->val = mul;
      current = current->next;
    }
    current->val = (current->val * 2) % 10;
    return head;
  }
};