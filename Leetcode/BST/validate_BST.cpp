/*


98. Validate Binary Search Tree
Solved
Medium
Topics
Companies
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

/* Using Recursive Approach */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool BST(TreeNode* root, long min, long max){
        if(!root)
            return 1;
        if(root->val <= min || root->val >= max)
            return 0;
        return (BST(root->left, min, root->val) && BST(root->right, root->val, max));
    }
    bool isValidBST(TreeNode* root) {
        return BST(root, LONG_MIN, LONG_MAX);   // here it means that on going left we will set the max value as 
        // root->val and no value should be greater than that on the left side
        // similarly on going right we will set the min value as root->val so that no value on the right should be lesser than the min value of the root node
    }
};

/* Iterative approach */
// struct BST{
//     TreeNode* root;
//     long min;
//     long max;
// };

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         stack<BST>st;
//         st.push({root, LONG_MIN, LONG_MAX});
//         while(!st.empty()){
//             auto [temp, min, max] = st.top();
//             st.pop();
//             if(temp->val <= min || temp->val >= max)
//                 return 0;
//             if(temp->right)
//                 st.push({temp->right, temp->val, max});
//             if(temp->left)
//                 st.push({temp->left, min, temp->val});
//         }
//         return 1;
//     }
// };

