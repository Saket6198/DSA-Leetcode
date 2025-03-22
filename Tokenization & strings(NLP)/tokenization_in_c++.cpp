/*

Write a function tokenize_sentence(sentence: str) -> List[str] that takes a sentence and returns a list of words (tokens) by splitting the sentence on spaces. Punctuation marks should be treated as separate tokens.

For example, given the sentence: "I love programming!" The function should return: ["I", "love", "programming", "!"]

Input Format

A single string sentence containing the input text (1 ≤ len(sentence) ≤ 1000).

Constraints

The sentence will contain alphabets, punctuation marks, and spaces. No leading or trailing spaces.

Output Format

A list of tokens as strings.

Sample Input 0

I love programming!
Sample Output 0

["I", "love", "programming", "!"]
Sample Input 1

Hello, how are you?
Sample Output 1

["Hello", ",", "how", "are", "you", "?"]


*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, temp;
    vector<string>v;
    cout<<"Enter : ";
    getline(cin, s);
    for(int i=0; i<s.size(); i++){
        if(isalnum(s[i])){
            // cout<<s[i]<<endl;
            temp += s[i];
        }
        else if(!(isalnum(s[i])) && s[i] != ' '){
            v.push_back(temp);
            temp = "";
            v.push_back(string(1, s[i]));
        }
        else{
            if (!temp.empty())
                v.push_back(temp);
            temp = "";
            
        }
    }
    if(temp.size() > 0)
        v.push_back(temp);
    cout<<"Output : "<<endl;
    // for(auto i : v){
    //     cout<<i<<endl;
    // }
    // cout<<v.size();
    cout<<"[";
    for(auto i : v){
        cout<<'"'<<i<<'"';
        if(i != v[v.size()-1])
            cout<<", ";
    }
    cout<<"]";
}