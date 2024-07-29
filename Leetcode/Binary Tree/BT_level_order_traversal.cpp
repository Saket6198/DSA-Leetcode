/*
102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000


*/

#include<iostream>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};  // if root itelf is null, we will return null
        vector<vector<int>>ans;     // creating a 2d vector and a queue of type TreeNode
        queue<TreeNode*>q;
        q.push(root);   // pushing root in the queue first
        while(!q.empty()){
            vector<int>row; // this will store its child in proper 2 sized vector in the 2d vector
            int s = q.size();
            for(int i=0; i<s; i++){     // for loop until we get all the childs
                auto temp = q.front();
                q.pop();
                row.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp -> right)
                    q.push(temp->right);
            }
            ans.push_back(row);  
        }
        return ans;      
    }
};

