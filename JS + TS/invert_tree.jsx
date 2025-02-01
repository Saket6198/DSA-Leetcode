/*
226. Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/


/**
 * Definition for a binary tree node.
 */
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */


var invertTree = function(root) {
    if(!root)
        return null;
    let q = [root];
    while(q.length > 0){
        let s = q.length;
        while(s--){
            let temp = q.shift();
            let lnode = temp.left;
            temp.left= temp.right;
            temp.right = lnode;
            if(temp.left)
                q.push(temp.left);
            if(temp.right)
                q.push(temp.right);
        }
    }
    return root;
};

