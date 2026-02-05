/*111. Minimum Depth of Binary Tree
Solved
Easy
Topics
premium lock icon
Companies
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000


*/

/* Recursive approach but goes thru all tree thus less time and space efficient*/

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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return (1 + min(minDepth(root->left), minDepth(root->right)));
    }
};

/* Iterative Approach, ends as soon as it finds the first min so time efficient */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int count = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto temp = q.front(); 
                q.pop();
                if(!temp ->left && !temp ->right)// if it reaches the leaf node, return the count/min dist
                    return count;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)     // if left & right exist, we will push it into the queue
                    q.push(temp->right);
            }
            count++;    // after each level iteration, we will increase the count by 1
        }
        return count;
    }
};
