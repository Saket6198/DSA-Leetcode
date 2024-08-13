/*
3248. Snake in Matrix

There is a snake in an n x n matrix grid and can move in four possible directions. Each cell in the grid is identified by the position: grid[i][j] = (i * n) + j.

The snake starts at cell 0 and follows a sequence of commands.

You are given an integer n representing the size of the grid and an array of strings commands where each command[i] is either "UP", "RIGHT", "DOWN", and "LEFT". It's guaranteed that the snake will remain within the grid boundaries throughout its movement.

Return the position of the final cell where the snake ends up after executing commands.

 

Example 1:

Input: n = 2, commands = ["RIGHT","DOWN"]

Output: 3

Explanation:

0	1
2	3
0	1
2	3
0	1
2	3
Example 2:

Input: n = 3, commands = ["DOWN","RIGHT","UP"]

Output: 1

Explanation:

0	1	2
3	4	5
6	7	8
0	1	2
3	4	5
6	7	8
0	1	2
3	4	5
6	7	8
0	1	2
3	4	5
6	7	8
 

Constraints:

2 <= n <= 10
1 <= commands.length <= 100
commands consists only of "UP", "RIGHT", "DOWN", and "LEFT".
The input is generated such the snake will not move outside of the boundaries.

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int a = 0, b = 0; // Starting position (0, 0)
        for (auto& command : commands) {
            if (command == "UP") {
                a--; // Move up
            } else if (command == "DOWN") {
                a++; // Move down
            } else if (command == "LEFT") {
                b--; // Move left
            } else if (command == "RIGHT") {
                b++; // Move right
            }
        }
        return (a * n) + b; // Calculate final position
    }
};

int main() {
    int size, numCommands;
    cout << "Enter the size of the grid: ";
    cin >> size;
    
    cout << "Enter the number of commands: ";
    cin >> numCommands;
    
    vector<string> commands(numCommands);
    cout << "Enter commands (UP, DOWN, LEFT, RIGHT): " << endl;
    for (auto& command : commands) {
        cin >> command;
    }
    
    Solution sol;
    cout << "Final position of the snake: " << sol.finalPositionOfSnake(size, commands) << endl;    
    return 0;
}