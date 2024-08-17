/*

199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

#include<iostream>
#include<queue>
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

/* using BFS */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return{};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};

/* Using recursion */
