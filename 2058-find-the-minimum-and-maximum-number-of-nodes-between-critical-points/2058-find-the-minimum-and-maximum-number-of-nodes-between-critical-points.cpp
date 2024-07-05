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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result(2, -1);
        if(head == NULL || head->next == NULL){
            return result;
        }

        ListNode *prevNode = head, *currNode = head->next, *nextNode = head->next->next;

        int first = -1, last = -1, prevPoint = -1;
        int pointer = 1, minDistance = INT_MAX, maxDistance = -1;
        while(nextNode != NULL){
            if((currNode->val > prevNode->val && currNode->val > nextNode->val) ||
                (currNode->val < prevNode->val && currNode->val < nextNode->val)){
                if(prevPoint == -1){
                    prevPoint = 1;
                    first = pointer;
                    last = pointer;
                } else {
                    minDistance = min(minDistance, pointer-last);
                    last = pointer;
                }
            }
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode->next;
            pointer++;
        }
        maxDistance = last-first;

        if(first != last){
            result[0] = minDistance;
            result[1] = maxDistance;
        }
        return result;
    }
};