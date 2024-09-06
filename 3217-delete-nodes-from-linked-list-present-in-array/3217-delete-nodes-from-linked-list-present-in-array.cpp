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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = head;
        unordered_set<int> val(nums.begin(),nums.end());
        while(temp!=NULL){
            if(val.contains(temp->val))
                temp = temp->next;
            else
                break;
        }
        ListNode* start = temp;
        while(start->next!=NULL){
            if(val.contains(start->next->val)){
                start->next = start->next->next;
            }
            else{
                start = start->next;
            }
        }
        return temp;
    }
};