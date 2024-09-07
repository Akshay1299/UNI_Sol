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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     bool isMatch(ListNode* head, TreeNode* root) {
       
        if (head == NULL) return true; 
        if (root == NULL) return false; 

        if (head->val != root->val) return false;

        return isMatch(head->next, root->left) || isMatch(head->next, root->right);
    }
    bool f(ListNode* &head,TreeNode* &root){
        if(root==NULL) return false;

        if(head->val==root->val){
            ListNode* num = head;
            if(isMatch(num,root)){
                return true;
            }
        }
        bool flag1 = f(head,root->left);
        if(flag1==true) return true;
        bool flag2 = f(head,root->right);
        if(flag2==true) return true;

        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* temp = head;
        return f(head,root);
    }
};