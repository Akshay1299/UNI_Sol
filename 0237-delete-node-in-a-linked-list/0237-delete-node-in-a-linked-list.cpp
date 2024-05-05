/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* popLast(ListNode* node) {
        if (node == nullptr)
            return node;
        if (node->next == nullptr)
            return nullptr;
        node->next = popLast(node->next);
        return node;
    }
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr)
            return;
        ListNode* it = node->next;
        ListNode* t = node;
        while (it != nullptr) {
            swap(t->val, it->val);
            t = t->next;
            it = it->next;
        }
        node = popLast(node);
    }
};