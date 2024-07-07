/*
2073. Time Needed to Buy Tickets

There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person at position k (0-indexed) to finish buying tickets.

 

Example 1:

Input: tickets = [2,3,2], k = 2
Output: 6
Explanation: 
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.
Example 2:

Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
 

Constraints:

n == tickets.length
1 <= n <= 100
1 <= tickets[i] <= 100
0 <= k < n
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         int i, t = 0;
//         queue<int>q;
//         for(i =0; i<tickets.size(); i++){
//             q.push(i);
//         }
//         while(tickets[k] != 0){
//             tickets[q.front()]--;
//             t++;
//             if(tickets[q.front()] == 0)
//                 q.pop();
//             else{
//                 q.push(q.front());
//                 q.pop();
//             }
//         }
//         return t;
//     }
// };

/* Without queue SC: O(1) */

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0, i = 0;
        for(i = 0; i<tickets.size(); i++){
            if(i > k)
                time += min(tickets[k]-1, tickets[i]); // for people in queue behind tickets[k], they can only get at max tickets[k]-1 tickets;
            else
                time += min(tickets[k], tickets[i]);    // for people in queue greater than tickets[k], they can at max only get tickets[k] tickets
        }
        return time;
    }
};

/*
eg: k = 2
    2 3 2 ,time = 2
    1 2 1 ,time = 4
    0 1 0 ,time = 6

eg: k = 0
    5 1 1 1 ,time = 3
    4 0 0 0 ,time = 4
    3
    2
    1
    0        ,time = 8 

*/
