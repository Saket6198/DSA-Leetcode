/*
92. Reverse Linked List II

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?


*/
class ListNode {
    val: number;
    next: ListNode | null;
    constructor(val?: number, next?: ListNode | null) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
}

function reverseBetween(head: ListNode | null, left: number, right: number): ListNode | null {
    if (!head || left === right || head.next === null) return head;

    const dummy = new ListNode(0); // Dummy node to simplify edge cases
    dummy.next = head;
    let prev: ListNode | null = dummy;

    // Step 1: Reach the node just before the 'left' position
    for (let i = 1; i < left; i++) {
        if (prev) prev = prev.next!;
    }

    // Step 2: Reverse the sublist from left to right
    let curr: ListNode | null = prev?.next || null;
    let next: ListNode | null = null;

    for (let i = 0; i < right - left; i++) {
        if (curr && curr.next) {
            next = curr.next;
            curr.next = next.next;
            next.next = prev?.next || null;
            if (prev) prev.next = next;
        }
    }

    // Return the head of the modified list
    return dummy.next;
}