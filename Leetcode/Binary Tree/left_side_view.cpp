/*
Left View of Binary Tree

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Examples :

Input:
   1
 /  \
3    2
Output: 1 3

Input:

Output: 10 20 40
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105



*/

#include<iostream>
#include<queue>
#include<vector>

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

vector<int> leftView(Node *root)
{

    if(!root)
        return {};
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        bool left = 0;
        while(s--){
            auto temp = q.front();
            q.pop();
            if(left == 0){
                left = 1;
                ans.push_back(temp->data);
            }
            if(temp->left)
                q.push(temp->left);
            if(temp -> right)
                q.push(temp -> right);
        }
    }
    return ans;
}

/* Using Recursion */
void left(Node* root, int level, vector<int>&ans){   // passing level by reference caused undefined behaviour so & not used
    if(!root)
        return;
    if(level == ans.size())     // ans size increases first
        ans.push_back(root->data);
    left(root->left, level+1, ans);
    left(root->right, level+1, ans);
}

vector<int> leftView(Node *root)
{
    if(!root)
        return {};
    vector<int>ans;
    int count = 0;
    left(root, count, ans);
    return ans;
}