/*
783. Minimum Distance Between BST Nodes
Solved
Easy
Topics
premium lock icon
Companies
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
 

Note: This question is the same as 530:*/

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
    int minDiffInBST(TreeNode* root) {
        stack<tuple<TreeNode*, bool>>st;
        st.push({root, 0});
        vector<int>ans;
        while(!st.empty()){
            auto [temp, seen] = st.top();
            st.pop();
            if(seen){
                ans.push_back(temp->val);
            }else{
                if(temp->right){
                    st.push({temp->right, 0});
                }
                st.push({temp, 1});
                if(temp->left){
                    st.push({temp->left, 0});
                }
            }
        }
        int m = INT_MAX;
        for(int i=1; i<ans.size(); i++){
            m = min(m, abs(ans[i-1] -ans[i]));
        }
        return m;
    }
};