/*Count Leaves in Binary Tree

Given a Binary Tree of size n, You have to count leaves in it. For example, there are two leaves in the following tree

        1
     /      \
   10      39
  /
5
 

Examples:

Input:
Given Tree is 
               4
             /   \
            8     10
           /     /   \
          7     5     1
         /
        3 
Output: 3
Explanation: Three leaves are 3, 5 and 1.
Input:
Given Tree is
          50
        /    \
      30      70
     /  \    /  \
    20   40 60   80
             \
             65
Output: 4
Explanation: Four leaves are 20, 40, 65 and 80.
Input:
Given Tree is 
          30
        /    \
      25      35
     /  \      \
    20   28     40
        /
       27
Output: 3
Explanation: Three leaves are 20, 27 and 40.
 Constraints:
1<= number of nodes <= 105
1<= node->data <= 105 */


class Node
{
    constructor(x){
        this.data=x;
        this.left=null;
        this.right=null;
    }
}

class Solution {
    countLeaves(root) {
        if(!root)
            return 0;
        let count = 0;
        if(!root.left && !root.right)
            return 1;
        return (this.countLeaves(root.left) + this.countLeaves(root.right));
    }
}