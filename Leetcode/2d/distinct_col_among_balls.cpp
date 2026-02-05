#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> color, coun; // color[first] color of the ball first and coun[sec] is the no of balls with color sec
        vector<int> ans(queries.size(), 0);
        unsigned j = 0;
        for (auto &i : queries)
        {
            unsigned first = i[0], sec = i[1];
            if (color.count(first) > 0)
            {                               // if ball is already coloured before
                unsigned c0 = color[first]; // get the prev color id and decrement it by 1
                coun[c0]--;
                if (coun[c0] == 0)
                    coun.erase(c0);
            }
            color[first] = sec; // else if not present then set the color of ball first by color sec
            coun[sec]++;        // increment the no of balls colored by color sec
            ans[j++] = coun.size();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int size;
    cout << "Enter the size of the 2d Array: ";
    cin >> size;
    cout << "Enter the elements of the 2d vector: ";
    vector<vector<int>> queries(size, vector<int>(2));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> queries[i][j];
        }
    }
    vector<int>ans = sol.queryResults(size, queries);
    for(auto i: ans){
        cout << i << " ";
    }
}
