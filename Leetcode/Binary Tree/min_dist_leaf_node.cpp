#include<iostream>
#include<queue>

using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}   
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DFS Approach Space efficient but not Time */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int count = 0;
        if(!root->left)
            return(1+minDepth(root->right));    // if the left subnode is empty, we account for the root node and move to the non empty root->right 
            
        if(!root->right)
            return(1+minDepth(root->left)); // if the left subnode is empty, we account for the root node and move to the non empty root->left
        count++;
        return(count + min(minDepth(root->left), minDepth(root->right)));
    }
};

/* BFS Space inefficient but Time efficient */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int count = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto temp = q.front(); 
                q.pop();
                if(!temp ->left && !temp ->right)// if it reaches the leaf node, return the count/min dist
                    return count;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)     // if left & right exist, we will push it into the queue
                    q.push(temp->right);
            }
            count++;    // after each level iteration, we will increase the count by 1
        }
        return count;
    }
};