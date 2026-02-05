/*
653. Two Sum IV - Input is a BST

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

*/

#include<bits/stdc++.h>

using namespace std;

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
    bool findpair(TreeNode* root, unordered_set<int>& seen, int k){
        if(!root)
            return 0;
        if(seen.count(k - root->val))
            return 1;
        seen.insert(root->val);
        return (findpair(root->left, seen, k) || findpair(root->right, seen, k));
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>seen;
        return findpair(root, seen, k);
    }
};

/* Iterative Approach */
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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>st;
        st.push(root);
        unordered_set<int>seen;
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            if(seen.count((k- temp->val)))
                return 1;
            seen.insert(temp->val);
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return 0;
    }
};
