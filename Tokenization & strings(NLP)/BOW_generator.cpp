/*

You are given a list of unique words and a document (a string). Your task is to generate a Bag of Words feature vector for the document. This vector should contain the frequency count of each word in the list within the document.

The order of the words in the output vector should correspond to the order of the words in the input list.

Example 1:

Input:

5 the quick brown fox jumps The quick fox jumps over the lazy dog

Output:

2 1 1 1 1

Explanation:

'the' appears 2 times.
'quick' appears 1 time.
'brown' appears 1 time.
'fox' appears 1 time.
'jumps' appears 1 time.
Input Format

The first line contains an integer n denoting the number of unique words in the list. The second line contains n space-separated strings, representing the list of words. The third line contains a string document that represents the document where we need to count the frequency of each word.

Constraints

1 ≤ n ≤ 100 1 ≤ length of each word ≤ 20 1 ≤ length of the document ≤ 1000 The words in the document are case-insensitive. The document may contain punctuation, which should be ignored.

Output Format

Print a space-separated list of integers representing the frequency count of each word in the list, in the same order as they appear in the input word list.

Sample Input 0

5
the quick brown fox jumps
The quick fox jumps over the lazy dog
Sample Output 0

2 1 0 1 1
Sample Input 1

3
apple banana orange
apple orange apple apple banana
Sample Output 1

3 1 1

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, temp, b;
    int n;
    // cout<<"Enter n";
    cin>>n;
    vector<string>v(n);
    // cout<<"Enter unique";
    cin.ignore(); // Clear the input buffer
    getline(cin, b);
    // cout<<"Enter full";
    getline(cin, s);
    int j=0;
    for(int i=0; i<b.size(); i++){
        if(isalnum(b[i])){
            temp += tolower(b[i]);
        }else{
            if(temp.size()> 0)
                v[j++]=temp;
            temp="";
        }
    }
    if(temp.size() > 0)
        v[j]=temp; 
    // cout<<v.size(); 
    // for(const auto &i : v)
    //     cout<<i<<endl;
    temp="";
    unordered_map<string, int>seen;
    for(auto i=0; i<s.size(); i++){
        if(isalnum(s[i])){
            temp += tolower(s[i]);
        }else{
            if(temp.size() > 0){
                // if(seen.count(temp)==0)
                //     v.push_back(temp);
                seen[temp]++;
            }
            temp ="";
        }
    }
    if(temp.size() > 0)
        seen[temp]++;
    // cout<<"Output : "<< endl;
    for(auto i : v)
        cout<<seen[i]<<" ";
}