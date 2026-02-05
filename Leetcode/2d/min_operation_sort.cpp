/*
2471. Minimum Number of Operations to Sort a Binary Tree by Level
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:


Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 2:


Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.
Example 3:


Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
All the values of the tree are unique.
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
    int minSwaps(vector<pair<int, int>>&ans){
        int cnt = 0;
        sort(ans.begin(), ans.end());   // sorting based on values
        vector<int>seen;
        for(int i=0; i<ans.size(); i++){    // now applying a for loop to check all position
            while(ans[i].second != i){  // we will do this operation until the index are their correct place
                int temp = ans[i].second;
                if(temp != i){  // if not at correct position, swap and increase counter
                    swap(ans[i], ans[temp]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;  // first doing BFS on tree to get all nodes at the level
        q.push(root);
        int cnt = 0,s;
        while(!q.empty()){
            vector<pair<int, int>>ans;  // storing value and index to apply index sorting
            int idx=0;
            s = q.size();
            while(s--){
                auto temp = q.front();
                q.pop();
                if(temp->left){
                    ans.push_back({temp->left->val, idx++});
                    q.push(temp->left);
                }
                if(temp->right){
                    ans.push_back({temp->right->val, idx++});
                    q.push(temp->right);
                }
            }
            cnt += minSwaps(ans);
        }
        return cnt;
    }
};