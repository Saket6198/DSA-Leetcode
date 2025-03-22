/*


You are given a sentence as input. Your task is to tokenize the sentence into words, ensuring that punctuation marks remain attached to the words they belong to. For example:

"Hello, world!" should tokenize into ["Hello,", "world!"]
"It's a sunny day." should tokenize into ["It's", "a", "sunny", "day."]
You should implement a function tokenize_sentence(sentence: str) -> List[str] that takes a single string as input and returns a list of strings, where each string is a word or a token, with punctuation marks attached to the appropriate word.

Input Format

A single string sentence of length n (1 ≤ n ≤ 10^5), representing the sentence to be tokenized.

Constraints

The input sentence will consist of lowercase and uppercase alphabets, numbers, spaces, and punctuation marks like ., ,, !, ?, ', ".

Output Format

A list of words or tokens. Each token will be a string containing a word with its attached punctuation marks (if any).

Sample Input 0

Hello, world!
Sample Output 0

["Hello,", "world!"]
Sample Input 1

It's a sunny day.
Sample Output 1

["It's", "a", "sunny", "day."]
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, temp;
    cout<<"Enter: ";
    getline(cin, s);
    vector<string>v;
    for(int i=0; i<s.size(); i++){
        if(isalnum(s[i])){
            temp += s[i];
        }else if(!isalnum(s[i]) && s[i] != ' '){
            temp += s[i];
        }
        else{
            if(temp.size() > 0){
                v.push_back(temp);
            }
            temp ="";
        }
    }
    if(temp.size() > 0)
        v.push_back(temp);
    cout<<"Output : "<<endl;
    // for(auto i : v){
    //     cout<<i<<" ";
    // }
    cout<<"[";
    for(auto i : v){
        cout<<'"'<<i<<'"';
        if(i != v[v.size()-1])
            cout<<", ";
    }
    cout<<"]";

}