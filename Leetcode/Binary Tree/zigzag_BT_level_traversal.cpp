/*
103. Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100


*/

#include<iostream>
#include<deque>
#include<vector>

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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>>ans;
        deque<TreeNode*>q;  //creating a deque to do opr on front and back
        q.push_back(root);
        bool order = 1;
     while(!q.empty()){
            int s = q.size();
            vector<int>level;
            while(s--){
                TreeNode* temp;
                if(order == 1){
                    temp = q.front();
                    q.pop_front();
                    if(temp ->left)
                        q.push_back(temp->left);
                    if(temp->right)
                        q.push_back(temp->right);
                }else if(order == 0){
                    temp = q.back();
                    q.pop_back();
                    if(temp ->right)
                        q.push_front(temp->right);
                    if(temp->left)
                        q.push_front(temp->left);
                }
                level.push_back(temp->val);
            }
            ans.push_back(level);
            order = !order;
            level = {};
        }
        return ans;
    }
};