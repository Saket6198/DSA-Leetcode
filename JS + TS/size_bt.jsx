/*
Size of Binary Tree

Given a binary tree, you have to return the size of it. Size of binary tree is defined as number of nodes in it.

Examples:

Input:      
       1
     /  \
    2    3
Output: 3
Explanation: There are three nodes in given binary tree.
Input:
      10
     /  \
   5     9
   \    / \
    1 3   6
Output: 6
Explanation: There are six nodes in given binary tree.
Input:
      1
Output: 1
Explanation: There is one nodes in given binary tree.
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105

*/


class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Solution {
    /**
    * @param Node node

    * @returns number
    */
    
    countnodes(node, count){
        if(!node)
            return count;
        count++;
        count = this.countnodes(node.left, count);
        count = this.countnodes(node.right, count);
        return count;
    }
    
    getSize(node) {
        let count = 0;
        count = this.countnodes(node, count);
        return count;
    }
}
