/*
222. Count Complete Tree Nodes
Solved
Easy
Topics
Companies
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/* Using Integer recursion  */

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);    // counts the total no of nodes on left and right, else return NULL
    }
};

/* Using a counter recursive */

class Solution {
public:

    int countNodes(TreeNode* root) {
        int count = 0;
        total(root, count);
        return count;
    }

    void total(TreeNode* root, int &count){     // pass by reference
        if (root == NULL)
            return;
        
        count++;        // we are only incrementing the counter everytime and not returning anything that is why it is void return type
        total(root->left, count);   // increases count whenever root -> left is not null
        total(root->right, count);  // increases count whenever root -> right is not null
    }
};

/* Using Iterative Approach */
class Solution {
  public:
    int getSize(TreeNode* node) {
        if(!node)
            return 0;
        int count = 0;
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty()){
            auto temp = q.front();
            count++;
            q.pop();
            if(temp -> left)
                q.push(temp->left);
            if(temp -> right)
                q.push(temp -> right);
        }
        return count;
    }
};