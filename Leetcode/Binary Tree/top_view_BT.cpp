#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int s){
        data = s;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void find(Node* root, int pos, int &l, int &r){
        if(!root)   // if root does not exist simply return
            return;
        l = min(l, pos);    /* left size will go in -ve so we will take always min until we reach the correct left height (in -ve) */
        r = max(r, pos);    /* right size will go in +ve so we will take always max until we reach the max correct right height (in +ve) */
            
        find(root->left, pos-1, l, r);   // when we go left, we decrease pos by 1
        find(root->right, pos+1, l, r);  // when we go right, we increase pos by 1
    }
    vector<int> topView(Node *root){
        if(!root)
            return {};  
        int l = 0, r = 0;   
        find(root, 0, l, r);    // by pass by reference we get value of l and r
        vector<int>ans(r - l + 1);  // to calculate size we subtract right(+ve) by left(-ve)
        vector<int>filled(r-l+1, 0);    // we will initalize with 0 and same size
        queue<Node*>q;      
        queue<int>index;    // this will store the actual index position according the position
        q.push(root);
        index.push(l * -1); // initially we will be pushing the root index which is left height
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            int position = index.front();
            index.pop();
            if(!filled[position]){      // if filled is not filled we will insert at that position
                ans[position] = temp->data;
                filled[position] = 1;
            }
            if(temp->left){
                q.push(temp->left);
                index.push(position-1); // if going left we will decrease position by 1 and vice versa
            }                
            if(temp->right){
                q.push(temp->right);
                index.push(position+1);
            }
        }
        return ans;
    }
};

