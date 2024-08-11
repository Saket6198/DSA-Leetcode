/*

100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 
*/ 
#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    struct Node* left;
    struct Node* right;

    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};
/* Using Recursive approach TC: O(N) SC: O(N) */

class Solution {
public:
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2)
            return 1;
        if(!r1 && r2 || r1 && !r2){
            return 0;
        }
        if(r1->val != r2->val){
            return 0;
        }
        return isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);  // return true if both function returns the identical or same return no
    }
};



