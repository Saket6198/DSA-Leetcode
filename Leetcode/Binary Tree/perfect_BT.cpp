/*
    Perfect Binary Tree
Difficulty: EasyAccuracy: 45.43%Submissions: 18K+Points: 2
Given a Binary Tree, write a function to check whether the given Binary Tree is a prefect Binary Tree or not. A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level.

Example 1:

Input: 
          7
      /  \
     4    9
Output: YES
Explanation: 
As the root node 7 has two children and 
two leaf nodes 4 and 9 are at same level 
so it is a perfect binary tree.
Example 2:

Input: 
                   7
              /   \
             3     8
           /   \     \
          2     5     10
        /
       1
Output: NO
Your task:

You don't need to read input or print anything. Your task is to complete the function isPerfect() which takes root node of the tree as input parameter and returns a boolean value.If the tree is a perfect binary tree return true other wise return false.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1<=T<=10^5
1<=N<=10^5
1<=data of node<=10^5

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    bool isPerfect(Node *root) {
        queue<Node*>q;
        q.push(root);
        int lvl = 0, leaf = 0;
        while(!q.empty()){
            lvl++;
            int s =q.size();
            while(s--){
                auto temp = q.front();
                q.pop();
                if((!temp->left && temp->right) || (temp->left && !temp->right))
                    return 0;
                if(!temp->left && !temp->right){
                    if (leaf == 0)    // if leaf found for the first time then set it
                        leaf = lvl;
                    else if (leaf != lvl)   // if leaf found at a different level then directly return false
                        return false;
                }      
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return 1;
    }
};