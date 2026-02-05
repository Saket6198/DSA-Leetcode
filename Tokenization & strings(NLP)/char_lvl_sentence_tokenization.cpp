/*
For this challenge, the input consists of a sentence and a token length. Your task is to split the sentence into substrings of the specified length while ensuring that punctuation marks are treated as separate tokens, regardless of the token length.

Specifically:

Given a sentence, split it into substrings where each substring is of the specified length. Punctuation marks (like ., ,, !, ?, etc.) should be treated as individual tokens, even if they appear in the middle of the sentence. The function tokenize_sentence(sentence: str, token_length: int) -> List[str] will take the sentence and token length as inputs and return a list of tokens.

Input Format

A string sentence (1 ≤ len(sentence) ≤ 1000) containing the input text. An integer token_length (1 ≤ token_length ≤ len(sentence)) specifying the length of each token.

Constraints

The sentence will contain lowercase and uppercase English letters, punctuation marks (., ,, !, ?, etc.), and spaces. Punctuation marks must always be treated as separate tokens. No leading or trailing spaces in the sentence.

Output Format

A list of tokens as strings, with each token following the specified length. Punctuation marks are treated as individual tokens.

Sample Input 0

I love programming!
4
Sample Output 0

['I', 'love', 'prog', 'ramm', 'ing', '!']
Sample Input 1

Code more!
3
Sample Output 1

['Cod', 'e', 'mor', 'e', '!']


*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, temp;
    vector<string>v;
    // cout<<"input: ";
    getline(cin, s);
    // cout<<"input no: ";
    int n, cnt = 0;
    cin>>n;
    for(int i=0; i<s.size(); i++){
        if(isalnum(s[i])){
            if(cnt < n){
            temp += s[i];
            cnt++;
            }else{
                v.push_back(temp);
                temp = "";
                temp += s[i];
                cnt = 1;
            }
        }else if(!isalnum(s[i]) && s[i] != ' '){
            if(temp.size() > 0){
                v.push_back(temp);
                temp ="";
            }   
            v.push_back(string(1, s[i]));
        }else{
            if(temp.size() > 0)
                v.push_back(temp);
            temp = "";
            cnt = 0;
        }
    }
    if(temp.size() > 0)
        v.push_back(temp);
    cout<<"[";
    for(const auto &k : v){
        cout<<"'"<<k<<"'";
        if(k != v[v.size()-1])
            cout<<", ";
    }
    cout<<"]";
}
