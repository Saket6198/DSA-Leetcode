
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