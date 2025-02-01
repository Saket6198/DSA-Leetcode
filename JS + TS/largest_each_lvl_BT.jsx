/*

515. Find Largest Value in Each Tree Row
Solved
Medium
Topics
Companies
Facebook
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1
*/


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
var largestValues = function(root) {
    if(!root)
        return [];
    let ans = [];
    let q = [root];
    while(q.length > 0){
        let s = q.length;
        let m = Number.MIN_SAFE_INTEGER;
        while(s--){
            let temp = q.shift();
            m = Math.max(m, temp.val);
            if(temp.left)
                q.push(temp.left);
            if(temp.right)
                q.push(temp.right);
        }
        ans.push(m);
    }
    return ans;
};