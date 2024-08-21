/*

145. Binary Tree Postorder Traversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

*/
#include<bits/stdc++.h>

using namespace std;

/* Using recursive approach */

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int s){
        val = s;
        left = right = NULL;
    }
};

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int>ans;
        stack<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            ans.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }    
};

/* Using Recursion */

class Solution {
public:
    void post(TreeNode* root, vector<int>& ans){
        if(!root)
            return;
        post(root->left, ans);
        post(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        post(root, ans);
        return ans; 
    }
};