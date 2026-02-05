/*

Size of Binary Tree

Given a binary tree, you have to return the size of it. Size of binary tree is defined as number of nodes in it.

Examples:

Input:      
       1
     /  \
    2    3
Output: 3
Explanation: There are three nodes in given binary tree.
Input:
      10
     /  \
   5     9
   \    / \
    1 3   6
Output: 6
Explanation: There are six nodes in given binary tree.
Input:
      1
Output: 1
Explanation: There is one nodes in given binary tree.
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105

*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    int getSize(Node* node) {
        if(!node)
            return 0;
        return 1 + getSize(node->left) + getSize(node->right);
    }
};