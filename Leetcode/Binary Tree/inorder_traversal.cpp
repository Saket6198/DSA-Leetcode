/*94. Binary Tree Inorder Traversal
Solved
Easy
Topics
Companies
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include<bits/stdc++.h>

using namespace std;
/* Using Iterative Approach */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}   
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            if(!root)
                return {};
            vector<int>ans;
            stack<TreeNode*>s1;
            stack<bool>visited; // to check if node is visited twice or not
            s1.push(root);
            visited.push(0);    // 0 means not visited, for first element
            while(!s1.empty()){
                TreeNode* temp = s1.top();
                s1.pop();
                bool flag = visited.top();
                visited.pop();
                if(!flag){  // if not visited
                    if(temp->right){ // if right child exists and not visited 
                        s1.push(temp->right);
                        visited.push(0);
                    }
                    s1.push(temp);  // push the root child now as it has been visited one time so 1 is pushed
                    visited.push(1);
                    if(temp->left){ // if left child exists and not visited
                        s1.push(temp->left);
                        visited.push(0);    //visited first time so 0 is pushed
                    }
                }else{
                    ans.push_back(temp->val);  // if visited twice then push the value in ans   
                }
            }
            return ans;
        }
    };

/* Using Recursion */

class Solution {
public:
    void inorder(TreeNode*root, vector<int>&ans){
        if(!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root, ans);
        return ans;
    }
};