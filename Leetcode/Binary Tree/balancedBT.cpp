/*
110. Balanced Binary Tree

Given a binary tree, determine if it is 
height-balanced

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

*/


#include<iostream>  
#include<vector>

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
    int height(TreeNode* root, bool &val){
        if(!root)
            return 0;
        int l = height(root->left, val);
        int r = height(root->right, val);
        if(abs(l-r) >1)
            val = 0;
        return(1+ max(l,r));
    }
    bool isBalanced(TreeNode* root) {
        bool valid = 1;
        if(!root)
            return 1;
        height(root, valid);
        return valid;
    }
};
