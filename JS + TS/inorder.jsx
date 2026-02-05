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


/* using iterative approach */

var inorderTraversal = function(root) {
    if(!root)
        return [];
    let stack = [root];
    let visited = [];
    let ans = [];
    stack.push(root);
    visited.push(0);
    while(stack.length > 0){
        let temp = stack.pop();
        let flag = visited.pop();
        if(!flag){
            if(temp.right){
                stack.push(temp.right);
                visited.push(0);
            }
            stack.push(temp);
            visited.push(1);
            if(temp.left){
                stack.push(temp.left);
                visited.push(0);
            }
        }else
            ans.push(temp.val);
            // visited.pop();
    }
    return ans;
};



var inorderTraversal = function(root) {
    function inorder(root, ans){
        if(!root)
            return [];
        inorder(root.left, ans);
        ans.push(root.val);
        inorder(root.right, ans);
    };
    const ans = [];
    inorder(root, ans);
    return ans;
};  