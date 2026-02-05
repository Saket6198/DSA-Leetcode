#include<bits/stdc++.h>
using namespace std;

// using my approach TC: (NLogN) SC: O(N)
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            multiset<long int>seen(nums.begin(), nums.end());
            int cnt = 0;
            while(*(seen.begin()) < k){
                cnt++;
                auto it1 = seen.begin(); auto it2 = next(it1);
                long int f = *it1;
                long int s = *it2;
                seen.erase(it1); seen.erase(it2);
                long int ans =  f*2 + s;
                // nums.insert(nums.begin(), ans);
                seen.insert(ans);
            }
            return cnt;
        }
    };

    // using optimized Priority Queue TC: O(NLogN) SC: O(N)

    class Solution {
        public:
            int minOperations(vector<int>& nums, int k) {
                priority_queue<long int, vector<long int>, greater<long int>>seen(nums.begin(), nums.end());
                int cnt = 0;
                while(seen.size() > 1 && seen.top() < k){
                    long int f = seen.top(); seen.pop();
                    long int s = seen.top(); seen.pop();
                    long int ans = f*2 + s;
                    seen.push(ans);
                    cnt++;
                } 
                return cnt;
            }
        };


