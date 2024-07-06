/*
2582. Pass the Pillow

There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

 

Example 1:

Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
After five seconds, the 2nd person is holding the pillow.
Example 2:

Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
After two seconds, the 3rd person is holding the pillow.
 

Constraints:

2 <= n <= 1000
1 <= time <= 1000

*/

#include<iostream>
#include<stdlib.h>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        return n - abs(n - 1 - (time % ((2*n) - 2)));
        }
};

/*

The code receives the input values:

n = 4 (the number of people in the circle)
time = 5 (the time at which we want to find the person holding the pillow)
The code calculates the number of complete cycles that have passed:

n * 2 - 2 = 4 * 2 - 2 = 6 (the number of seconds in one complete cycle)
5 / 6 = 0 (the number of complete cycles that have passed)
The code calculates the remaining time within the current cycle:

5 % 6 = 5 (the remaining time within the current cycle)
The code determines the direction of movement based on the remaining time:

If the remaining time is less than (n - 1), the pillow moves forward.
If the remaining time is greater than or equal to (n - 1), the pillow moves backward.
In this case, 5 < 3 (n - 1), so the pillow moves forward.
The code calculates the person holding the pillow:

n - Math.abs(n - 1 - time % (n * 2 - 2))
n = 4
Math.abs(n - 1 - time % (n * 2 - 2)) = Math.abs(4 - 1 - 5 % 6) = Math.abs(3 - 5) = Math.abs(-2) = 2
4 - 2 = 2
Therefore, at time=5, the person holding the pillow is person 2.
The formula used in the code is:

n - Math.abs(n - 1 - time % (n * 2 - 2))
Let's break it down:

n * 2 - 2 calculates the number of seconds in one complete cycle.

time % (n * 2 - 2) calculates the remaining time within the current cycle.

n - 1 represents the number of seconds it takes for the pillow to move from the first person to the last person.

Math.abs(n - 1 - time % (n * 2 - 2)) calculates the absolute difference between the remaining time and the time it takes for the pillow to move from the first person to the last person. This determines the position of the pillow within the current cycle.

Finally, n - Math.abs(n - 1 - time % (n * 2 - 2)) calculates the person holding the pillow by subtracting the absolute difference from n. This works because the pillow starts at person 1 and moves in a circular pattern.
*/