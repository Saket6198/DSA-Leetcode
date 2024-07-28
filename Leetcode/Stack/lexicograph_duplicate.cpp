/*
316. Remove Duplicate Letters

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order
 among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

*/

#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.length() == 1)
            return s;
        // first we will get the count of all the characters in the string using map
        unordered_map<char, int>seen;
        for(auto i : s){
            seen[i]++;
        }
        stack<char>st;  // stack keeps a pointer to the last inserted character
        unordered_set<char>q;     //set keeps a track of all the unique elements
        for(int i = 0; i<s.size(); i++){
                while(!st.empty() && st.top() > s[i] && seen[st.top()] != 0 && q.find(s[i]) == q.end()){     // to maintain the lexicographical order, if stack top is greater than present character we will pop it if and only if it's counter is not 0 i.e. there is another same character present in the string and also if it is not already present in the string
                    q.erase(st.top());
                    st.pop();
                }
                seen[s[i]]--;   // decrease counter of char by 1
                if(q.find(s[i]) != q.end())     // meaning it is preent in the stack then we continue; 
                    continue;
                st.push(s[i]);  //if unique then pushing it into the stack and set
                q.insert(s[i]);
        }
        s ="";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());    // to get the correct order after popping contents from the stack
        return s;
    }
};

int main(){
    Solution sol;
    string s;
    cout<<"Enter string: ";
    cin>>s;
    string ans = sol.removeDuplicateLetters(s);
    cout<<ans;
}

/*
nitial state:
Input: "abacb"
seen = {'a': 2, 'b': 2, 'c': 1}
stack = []
set = {}
Iteration 1 (i = 0):
Current character: 'a'
Before processing:
stack = []
set = {}
seen = {'a': 2, 'b': 2, 'c': 1}
Processing:
seen['a']-- => seen = {'a': 1, 'b': 2, 'c': 1}
Since 'a' is not in set and stack is empty, we push 'a' onto stack and add to set:
stack = ['a']
set = {'a'}
Iteration 2 (i = 1):
Current character: 'b'
Before processing:
stack = ['a']
set = {'a'}
seen = {'a': 1, 'b': 2, 'c': 1}
Processing:
seen['b']-- => seen = {'a': 1, 'b': 1, 'c': 1}
Since 'b' is not in set and stack top ('a') is less than 'b', we push 'b' onto stack and add to set:
stack = ['a', 'b']
set = {'a', 'b'}
Iteration 3 (i = 2):
Current character: 'a'
Before processing:
stack = ['a', 'b']
set = {'a', 'b'}
seen = {'a': 1, 'b': 1, 'c': 1}
Processing:
seen['a']-- => seen = {'a': 0, 'b': 1, 'c': 1}
Since 'a' is already in set, we skip this character.
No changes to stack and set:
stack = ['a', 'b']
set = {'a', 'b'}
Iteration 4 (i = 3):
Current character: 'c'
Before processing:
stack = ['a', 'b']
set = {'a', 'b'}
seen = {'a': 0, 'b': 1, 'c': 1}
Processing:
seen['c']-- => seen = {'a': 0, 'b': 1, 'c': 0}
Since 'c' is not in set and stack top ('b') is less than 'c', we push 'c' onto stack and add to set:
stack = ['a', 'b', 'c']
set = {'a', 'b', 'c'}
Iteration 5 (i = 4):
Current character: 'b'
Before processing:
stack = ['a', 'b', 'c']
set = {'a', 'b', 'c'}
seen = {'a': 0, 'b': 1, 'c': 0}
Processing:
seen['b']-- => seen = {'a': 0, 'b': 0, 'c': 0}
Since 'b' is already in set, we skip this character.
No changes to stack and set:
stack = ['a', 'b', 'c']
set = {'a', 'b', 'c'}
Final state:
stack = ['a', 'b', 'c']
Result string: "abc"

*/