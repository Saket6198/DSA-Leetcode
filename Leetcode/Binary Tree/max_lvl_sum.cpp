/*

1161. Maximum Level Sum of a Binary Tree

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.



Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2


Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int maxLevelSum(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int level = 1, ans = 0, m = INT_MIN;
        while (!q.empty())
        {
            int s = q.size();
            int sum = 0;
            while (s--)
            {
                auto temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            if (sum > m)
            {
                ans = level;
            }
            m = max(m, sum);
            level++;
        }
        return ans;
    }
};

TreeNode *buildTree(vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "NULL")
        return nullptr;
    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (i < nodes.size())
    {
        TreeNode *temp = q.front();
        q.pop();

        // left vaala

        if (nodes[i] != "NULL")
        {
            temp->left = new TreeNode(stoi(nodes[i]));
            q.push(temp->left);
        }
        i++;
        // right vaala
        if (i < nodes.size() && nodes[i] != "NULL")
        {
            temp->right = new TreeNode(stoi(nodes[i]));
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    cout << "Level-order traversal of the tree:" << endl;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "NULL ";
        }
    }
    cout << endl;
}



int main()
{
    int size;
    cout << "Enter the no of nodes in the tree: ";
    cin >> size;
    vector<string> nodes(size);
    cout << "Enter the values of the nodes: ";
    for (auto &i : nodes)
        cin >> i;
    TreeNode *root = buildTree(nodes);
    Solution sol;
    cout << "The tree is:" << endl;
    printTree(root);
    cout <<"smallest level x such that the sum of all the values of nodes at level x is maximal "<< sol.maxLevelSum(root);
}