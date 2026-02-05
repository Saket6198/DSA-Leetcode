/*

235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.



*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root->val == p->val || root->val == q->val) 
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root; // if both are found in left and right subtrees, then root is LCA
        return left ? left : right; // if one of them is found only, then that is LCA
    }
};

/* Iterative Approach */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }else if(p->val > root->val && q->val > root->val){
                root = root -> right;
            }else
                return root;
        }
        return NULL;
    }
};
/*  If p and q are on different sides of current root → current root is LCA

If one equals the root, it's the LCA

If both are smaller or both are larger, keep traversing in that direction
such is the property of BST

*/

int main(){
    int size;
    cout<<"Enter size of the tree";
    cin>>size;
    vector<int>tree(size);
    cout<<"Enter the tree elements";
    for(auto &i : tree)
        cin>>i;
    cout<<"Enter value of two nodes P and Q: ";
    int p_val, q_val;
    cin >> p_val >> q_val;
    TreeNode* p = new TreeNode(p_val);
    TreeNode* q = new TreeNode(q_val);
    TreeNode* root = new TreeNode(tree[0]);
    for(int i=1; i<size; i++){
        TreeNode* temp = root;
        while (true) {
            if (tree[i] < temp->val){
                if (temp->left) {
                    temp = temp->left;
                }else
                    temp->left = new TreeNode(tree[i]);
            break;
            }else{
                if(temp->right){
                    temp = temp->right;
                }else 
                    temp->right = new TreeNode(tree[i]);
            break;
            }
        }
    }
    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << lca->val << endl;
    return 0;
}
