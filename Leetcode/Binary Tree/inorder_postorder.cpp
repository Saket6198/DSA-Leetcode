/*
106. Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

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

// TC: O(N^2) SC: O(N) USING MATH FORMULA
class Solution {
public:
    int find(vector<int>&in, int target, int s, int e){
        for(int i=s; i<=e; i++){
            if(in[i] == target)
                return i;
        }
        return -1;
    }
    
    TreeNode* build(vector<int>&in, vector<int>&post, int Instart, int Inend, int idx){
        if(Instart > Inend)
            return NULL;
        TreeNode* root = new TreeNode(post[idx]);
        int position = find(in, post[idx], Instart, Inend);
        root->right = build(in, post, position+1, Inend,idx - 1);
        root->left = build(in, post, Instart, position-1, idx - (Inend - position) - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, postorder.size()-1,postorder.size()-1);
    }
};



int main(){
    Solution sol;
    cout<<"Enter size of inorder array: ";
    int size;
    cin>>size;
    vector<int>inorder(size);
    cout<<"Enter elements: ";
    for(int i=0; i<size; i++){
        cin>>inorder[i];
    }
    cout<<"Enter size of postorder array: ";
    cin>>size;
    vector<int>postorder(size);
    cout<<"Enter elements: ";
    for(int i=0; i<size; i++){
        cin>>postorder[i];
    }
    TreeNode* root = sol.buildTree(inorder, postorder);
    // ITERATING THRU THE ROOT TO DISPLAY
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}