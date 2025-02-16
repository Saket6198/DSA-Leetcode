/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<bits/stdc++.h>
using namespace std;

class FindElements {
    public:
        unordered_map<int, int>seen;;
        FindElements(TreeNode* root) {
            if(!root)
                return;
            stack<TreeNode*>st;
            root->val = 0;
            seen[root->val]++;
            st.push(root);
            while(!st.empty()){
                auto temp = st.top();
                st.pop();
                if(temp->right){
                    temp->right->val = temp->val * 2 + 2;
                    seen[temp->right->val]++;
                    st.push(temp->right);
                }
                if(temp->left){
                    temp->left->val = temp->val * 2 + 1;
                    seen[temp->left->val]++;
                    st.push(temp->left);
                }
            }
        }
        
        bool find(int target) {
            if(seen.count(target)> 0)
                return 1;
            return 0;
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */