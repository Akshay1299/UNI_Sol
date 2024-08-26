/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        
        if (!root)
            return ans;

        stack<pair<Node*, int>> st;

        st.push({root, -1});

        while (!st.empty()) {
            auto it = st.top();

            Node *node = it.first;
            int covIdx = it.second;
            
            if (covIdx + 1 < node->children.size()) {
                st.pop();
                st.push({node, covIdx + 1});

                st.push({node->children[covIdx + 1], -1});
            }
            else {
                ans.push_back(node->val);
                st.pop();
            }
        }

        return ans;
    }
};