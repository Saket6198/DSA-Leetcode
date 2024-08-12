/*

101. Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
*/

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *mirror(TreeNode *root)
    {
        if (!root)
            return NULL;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
        return root;
    }
    bool isIdentical(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 && !r2)
            return 1;
        if ((!r1 && r2) || (r1 && !r2))
        {
            return 0;
        }
        if (r1->val != r2->val)
            return 0;
        return ((isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right)));
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return 1;
        }
        TreeNode *lnode = mirror(root->left);
        bool result = isIdentical(lnode, root->right);
        return result;
    }
};
