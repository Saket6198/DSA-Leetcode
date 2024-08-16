/*

993. Cousins in Binary Tree

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.

*/
#include<iostream>
#include<queue>

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
    bool parents(TreeNode* root, int x, int y){
        if(!root)
            return 0;
        if(root->left && root->right){
            if(root->left->val == x && root->right->val == y)
                return 1;
            if(root->left->val == y && root->right->val == x)
                return 1;
        }
        return (parents(root->left, x, y) || parents(root->right, x, y));       
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return 1;
        queue<TreeNode*>q;
        q.push(root);
        int l1 = -1, l2 = -1, level = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto temp = q.front();
                q.pop();
                if(temp->val == x)
                    l1 = level;
                if(temp -> val== y)
                    l2 = level;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            level++;
            if(l1 != l2){   // if one of the node is not present in that level, they are not cousins
                return 0;
            if(l1 != -1)        // meaning we have found the levels of both the 
                break;
            }

        }
        return !parents(root, x, y);
    }
};