/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */

var preorderTraversal = function(root) {
    if(!root)
        return [];
    let stack = [root];
    let ans = [];
    while(stack.length > 0){
        let temp = stack.pop();
        ans.push(temp.val);
        if(temp.right)
            stack.push(temp.right);
        if(temp.left)
            stack.push(temp.left);
    }
    return ans;
};

