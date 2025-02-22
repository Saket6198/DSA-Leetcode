/*

1028. Recover a Tree From Preorder Traversal

We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

 

Example 1:


Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:


Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
Example 3:


Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]
 

Constraints:

The number of nodes in the original tree is in the range [1, 1000].
1 <= Node.val <= 109
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        TreeNode* recoverFromPreorder(string s) {
            vector<TreeNode*>st;
            int level, val;
            for(int i=0; i < s.size();){  // iterating until string size
                for(level = 0; s[i] == '-'; i++){    // counting the level size using dash
                    level++;
                }
                for(val = 0; i<s.size() && s[i] != '-'; i++){
                    val = val * 10 + s[i] - '0';    // to process more than 1 digit 
                }   
                TreeNode* node = new TreeNode(val);
                while(st.size() > level){   // checks the size and creates tree based on the level(brain fart lvl of idea, referred from some big brain guy in the solutions tab)
                    st.pop_back();
                }
                if(!st.empty()){
                    if(!st.back() -> left)  // if left is not filled then fill it first
                        st.back() -> left =  node;
                    else
                        st.back() -> right = node;
                }
                st.push_back(node);
            }
            return st[0];
        }
    };

    /*
    
    Example: Tree 1-2--3-4
Step	Stack (Nodes)	Explanation
1	[1]	Root node (1) added
2	[1, 2]	Node 2 added at depth 1
3	[1, 2, 3]	Node 3 added at depth 2
4	Pop 3, then [1, 2]	Node 4 is not depth 2, so 3 is removed

    */