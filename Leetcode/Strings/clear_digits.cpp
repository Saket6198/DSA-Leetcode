#include<bits/stdc++.h>
using namespace std;

// using stack O(N) space 
// class Solution {
//     public:
//         string clearDigits(string s) {
//             stack<char>st;
//             for(int i=0; i<s.size(); i++){
//                 if(isdigit(s[i]))
//                     st.pop();
//                 else
//                     st.push(s[i]);
//             }
//             if(st.empty()) return "";
//             string ans = "";
//             while(!st.empty()){
//                 ans += st.top();
//                 st.pop();
//             }
//             reverse(ans.begin(), ans.end());
//             return ans;
//         }
//     };

    // optimized in-place: O(1) space

    class Solution {
        public:
            string clearDigits(string s) {
                string ans = "";
                for(auto i : s){
                    if(isdigit(i))
                        ans.pop_back();
                    else
                        ans += i;
                }
                return ans;
            }
        };


    int main(){
        Solution sol;
        string s;
        cout<<"Enter the string: ";
        cin>>s;
        cout<<sol.clearDigits(s);   
    }