#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>>merged;
            int i=0, n = intervals.size();
            while(i < n && intervals[i][1] < newInterval[0]){
                merged.push_back(intervals[i]);
                i++;
            }
            while(i < n && intervals[i][0] <= newInterval[1]){
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                i++;
            }
            merged.push_back(newInterval);
            while(i < n){
                merged.push_back(intervals[i]);
                i++;
            }
            return merged;
        }
    };

    int main(){
        Solution s;
        int n;
        cout<<"Enter the size of the 2d vector: ";
        cin>>n;
        cout<<"Enter the elements of the 2d vector: ";
        vector<vector<int>>interval(n, vector<int>(2));
        for(auto i : interval){
            cin>>i[0]>>i[1];
        }        
        cout<<"Enter the new Interval ";
        vector<int>newInterval(2);
        cin>>newInterval[0]>>newInterval[1];
        vector<vector<int>>result = s.insert(interval, newInterval);
        cout<<"The merged intervals are: "<<endl;
        for(auto i : result){
            cout<<i[0]<<" "<<i[1]<<endl;
        }
        
    }
