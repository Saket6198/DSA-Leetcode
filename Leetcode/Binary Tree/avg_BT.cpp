/*

637. Average of Levels in Binary Tree
Solved
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
Example 2:


Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty()){
            double s = q.size(), avg = 0, size = s;
            while(size--){
                auto temp = q.front();
                q.pop();
                avg += temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);    
            }
            ans.push_back(avg/s);
        }
        return ans;
    }
};