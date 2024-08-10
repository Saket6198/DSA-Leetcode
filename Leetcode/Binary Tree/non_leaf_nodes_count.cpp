/*
Count Non-Leaf Nodes in Tree

Given a Binary Tree of size N, your task is to complete the function countNonLeafNodes(), that should return the count of all the non-leaf nodes of the given binary tree.

Example:

Input: 
Image
Output:
2
Explanation:
Nodes 1 and 2 are the only non leaf nodes.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105

*/
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        if(!root)
            return 0;
        int count = 0;
        if(root->left || root -> right){    // if either left or right node exists we increase the counter since it is a non leaf node
            count++;
        }
        return (count + countNonLeafNodes(root->left) + countNonLeafNodes(root->right));
    }
};