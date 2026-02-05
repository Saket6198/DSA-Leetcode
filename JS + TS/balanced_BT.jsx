
/*
110. Balanced Binary Tree

Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

*/

/*
 * Definition for a binary tree node.
 */
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
/**
 * @param {TreeNode} root
 * @return {boolean}
 */

class Solution{
    height(root, valid){
        if(!root)
            return 0;
        let l = this.height(root.left, valid);
        let r = this.height(root.right, valid);
        if(Math.abs(l-r) > 1)
            valid.value = false;
        return 1 + Math.max(l, r);
    }
}

var isBalanced = function(root) {
    if(!root)
        return 1;
    const solution = new Solution();
    let valid = { value: true };
    solution.height(root, valid);
    return valid.value;
};

