/*

116. Populating Next Right Pointers in Each Node

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 212 - 1].
-1000 <= Node.val <= 1000
 

Follow-up:

You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.


*/



// * Definition for _Node.
class _Node {
    val: number
    left: _Node | null
    right: _Node | null
    next: _Node | null
    constructor(val?: number, left?: _Node, right?: _Node, next?: _Node) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
        this.next = (next===undefined ? null : next)
    }
}

function connect(root: _Node | null): _Node | null {
    if(!root)
        return null;
    const q: _Node[] = [];
    q.push(root);
    while(q.length > 0){
        let rightNode: _Node | null = null;
        const levelsize = q.length;

        for(let i = 0; i<levelsize; i++){
            const curr = q.shift()!;
            curr.next = rightNode;
            rightNode = curr;
            if(curr.right && curr.left){ // since it is a perfect Binary tree so if right exist then left too will.
                q.push(curr.right);
                q.push(curr.left);
            }
        }
    }
    return root;
};

