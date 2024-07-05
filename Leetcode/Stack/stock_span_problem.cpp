/*
Stock span problem

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span 
100 is greater than equal to 100 and there are no more elements behind it so the span is 1,
80 is greater than equal to 80 and smaller than 100 so the span is 1,
60 is greater than equal to 60 and smaller than 80 so the span is 1,
70 is greater than equal to 60,70 and smaller than 80 so the span is 2,
60 is greater than equal to 60 and smaller than 70 so the span is 1,
75 is greater than equal to 60,70,60,75 and smaller than 100 so the span is 4,
85 is greater than equal to 80,60,70,60,75,85 and smaller than 100 so the span is 6. 
Hence the output will be 1 1 1 2 1 4 6.
Example 2:

Input: 
N = 6, price[] = [10 4 5 90 120 80]
Output:
1 1 2 4 5 1
Explanation:
Traversing the given input span 
10 is greater than equal to 10 and there are no more elements behind it so the span is 1,
4 is greater than equal to 4 and smaller than 10 so the span is 1,
5 is greater than equal to 4,5 and smaller than 10 so the span is 2,
90 is greater than equal to all previous elements so the span is 4,
120 is greater than equal to all previous elements so the span is 5,
80 is greater than equal to 80 and smaller than 120 so the span is 1,
Hence the output will be 1 1 2 4 5 1.

User Task:
The task is to complete the function calculateSpan() which takes two parameters, an array price[] denoting the price of stocks, and an integer N denoting the size of the array and number of days. This function finds the span of stock's price for all N days and returns an array of length N denoting the span for the i-th day.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ C[i] ≤ 105

Basically find the total no of elements smaller than index elements on the left side
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>ans(n, 1);   // we will initialise this vector by 1 according to the rule
        stack<int>st;
        for(int i=n-1; i>=0; i--){      // iterate throught the vector 
            while(!st.empty() && price[st.top()] < price[i]){   // while stack is not empty and stack top is lesser than ith element of price
                ans[st.top()] = st.top() - i;
                st.pop();
            }
            st.push(i); // if stack is empty, we will just push it 
        }
        while(!st.empty()){ // for edge cases lets say 6 7 10 , we will pop and add + 1 until the stack is emoty
            ans[st.top()] = st.top() + 1;       // adding 1 to the stack top and then inserting it at stack top index in ans vector
            st.pop();
        }
        return ans;
    }
};

/*  

LEETCODE SAME PROBLEM STATEMENT WITH MINOR VARIATION 

901. Online Stock Span
Solved
Medium
Topics
Companies
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
 
Input
["StockSpanner","next","next","next","next","next","next","next","next","next","next"]
[[],[28],[14],[28],[35],[46],[53],[66],[80],[87],[88]]
Output
[null,1,1,3,4,5,6,7,8,9,10]

Constraints:

1 <= price <= 105
At most 104 calls will be made to next.

*/

/* Solving with more space efficient method by stack using a count method/ iterator     */

class StockSpanner {
public:
    stack<pair<int, int>>st;    // creating a stack of pair of data type int, int which stores the price and the count of the next smaller element 
    StockSpanner() {
        //   this function is always empty and is always used as a initialisation function which creates the stack and the iteger
    }
    
    int next(int price) {
        int ct = 1;     // initially we will initialise count no with 1 indicating the presence of the no itself if no smaller element is present 
        while(!st.empty() && st.top().first <= price){  // while stack is not empty
        // and whenever a element greater than stack top arrives, we add the count to it as by 1 to indicate that now 2 nos are there smaller than it on the left side and then push the current element alongwith its count into the stack
            ct += st.top().second;
            st.pop();
        }
        st.push({price, ct});       // otherwise we will simply add it to the stack 
        return ct;                  // return the current elements count
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */