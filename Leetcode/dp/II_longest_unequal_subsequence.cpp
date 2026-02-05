/*
2901. Longest Unequal Adjacent Groups Subsequence II


You are given a string array words, and an array groups, both arrays having length n.

The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.

You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:

For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.
Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.

Note: strings in words may be unequal in length.

 

Example 1:

Input: words = ["bab","dab","cab"], groups = [1,2,2]

Output: ["bab","cab"]

Explanation: A subsequence that can be selected is [0,2].

groups[0] != groups[2]
words[0].length == words[2].length, and the hamming distance between them is 1.
So, a valid answer is [words[0],words[2]] = ["bab","cab"].

Another subsequence that can be selected is [0,1].

groups[0] != groups[1]
words[0].length == words[1].length, and the hamming distance between them is 1.
So, another valid answer is [words[0],words[1]] = ["bab","dab"].

It can be shown that the length of the longest subsequence of indices that satisfies the conditions is 2.

Example 2:

Input: words = ["a","b","c","d"], groups = [1,2,3,4]

Output: ["a","b","c","d"]

Explanation: We can select the subsequence [0,1,2,3].

It satisfies both conditions.

Hence, the answer is [words[0],words[1],words[2],words[3]] = ["a","b","c","d"].

It has the longest length among all subsequences of indices that satisfy the conditions.

Hence, it is the only answer.

 

Constraints:

1 <= n == words.length == groups.length <= 1000
1 <= words[i].length <= 10
1 <= groups[i] <= n
words consists of distinct strings.
words[i] consists of lowercase English letters.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dist(string a, string b){
        if(a.size() != b.size())
            return 0;
        int diff = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i]){
                if(diff > 1)
                    return 0;
                diff++;
            }
        }
        return diff==1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(), m=0;
        vector<int>dp(n, 1);
        vector<int>prev(n, -1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(dp[i] < dp[j] + 1 && ((groups[j] != groups[i]) && dist(words[j], words[i]))){
                    dp[i] = dp[j] + 1;
                    prev[i] = j; 
                }
            }
            if(dp[m] < dp[i])
                m = i;
        }
        
        vector<string>ans;
        for(int i=m; i != -1; i=prev[i]){
            ans.emplace_back(words[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*

🎯 Input:



words =  ["bab", "dab", "cab"]
groups = [   1 ,   2 ,   2  ]
Let’s label the indices:

0: "bab", group 1

1: "dab", group 2

2: "cab", group 2

🪜 STEP 1: Initialize



dp =    [1, 1, 1]       // each word is its own subsequence initially
prev =  [-1, -1, -1]    // no previous index yet
🧮 STEP 2: Build the DP Table
Loop i = 1 ("dab"):
We check all j < i → j = 0

Compare words[1] = "dab" with words[0] = "bab"

✔️ Same length ✅

✔️ Hamming distance = 1 (only 'd' vs 'b')

✔️ groups[1]=2 ≠ groups[0]=1 ✅

So valid!

Update:

dp[1] = dp[0] + 1 = 2
prev[1] = 0
Now:

dp =    [1, 2, 1]
prev =  [-1, 0, -1]
Loop i = 2 ("cab"):
We check j = 0 and j = 1

✅ Check with j = 0 ("bab"):

✔️ Hamming = 1

❌ groups[2]=2 == groups[0]=2 → Invalid

✅ Check with j = 1 ("dab"):

✔️ Hamming = 1 (only 'c' vs 'd')

❌ groups[2]=2 == groups[1]=2 → Invalid

So no valid transition → dp[2] remains 1.

Final dp, prev:




dp =    [1, 2, 1]
prev =  [-1, 0, -1]
🔍 STEP 3: Find Best Ending Index
We look for the maximum value in dp[]:




maxIndex = 1 (dp[1] = 2)
So the best sequence ends at index 1 (word = "dab").

🔁 STEP 4: Reconstruct the Sequence
We go backward from maxIndex = 1 using prev[]:

Start at i = 1 → words[1] = "dab" → add to answer

Move to prev[1] = 0 → words[0] = "bab" → add to answer

prev[0] = -1 → stop

We collected: ["dab", "bab"]

But this is backwards, so we reverse it:




Final Answer = ["bab", "dab"]


*/