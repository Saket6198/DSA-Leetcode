// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        if root.is_none(){
            return vec![];
        }
        let mut stack = vec![root.clone()];
        let mut ans = Vec::new();
        while let Some(Some(node)) = stack.pop() {
            let node = node.borrow();
            ans.push(node.val);
            if let Some(ref right) = node.right{
                stack.push(Some(right.clone()));
            }
            if let Some(ref left) = node.left {
                stack.push(Some(left.clone()));
            }
        }
        ans
    }
}

