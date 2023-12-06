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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;
        if(head->next==NULL) return true;
        
        ListNode *temp=head;
        bool flag=true;
        vector<int>nums;
        
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        
        for(int i=0,j=nums.size()-1;i<j;i++,j--){
            if(nums[i]!=nums[j]){
                flag = false;
                return flag;
            }
        }
        return flag;
    }
};