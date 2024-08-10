/*
104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

*/


#include<iostream>
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
    int depth(TreeNode* root){
        if(!root)
            return 0;   // if root itself is empty then it returns 0
        int left = depth(root->left);   // recursively goes to the most left part of the root
        int right = depth(root->right); // recursively goes to the most right part of the root
        return(1 + max(left, right));   // when it reaches the end node/leaf node first it will return 1 + max(0,0) above, then right subtree too will return 1 + max(1,1) ie 2 above until it reaches root 
 // then depth(root->right) is called with node 3, which returns 1 (as node 3 has no children).
// The depth for node 1 (root) is 1 + max(2, 1) = 3.
    }
    int maxDepth(TreeNode* root) { 
        return depth(root);
    }
};

/* Using Single Recursive Counter Function */
class Solution{
    public:
    int height(struct TreeNode* root){
        if(!root)
            return 0;
        int count = 0;
        count++;
        return(count+ max(height(root->left), height(root->right)));
    }
};