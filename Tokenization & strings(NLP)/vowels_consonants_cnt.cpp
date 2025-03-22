/*
You are given a list of sentences. Your task is to count the number of vowels and consonants in each sentence. For simplicity, consider vowels to be "a", "e", "i", "o", "u" (case-insensitive), and all other alphabetic characters to be consonants.

Implement the function count_vowels_and_consonants(sentences: List[str]) -> List[Tuple[int, int]] that returns a list of tuples, where each tuple contains two integers: the first one is the number of vowels, and the second one is the number of consonants in each sentence.

For each sentence in the list, return a tuple with the count of vowels and consonants.

Input Format

The first line contains an integer, n (1 ≤ n ≤ 10^5), representing the number of sentences. The next n lines contain sentences, each consisting of printable ASCII characters. Each sentence is a non-empty string, and its length will not exceed 100 characters.

Constraints

The length of each sentence will not exceed 100 characters. The total number of characters across all sentences will not exceed 10^6 characters.

Output Format

Return a list of tuples where each tuple consists of two integers. The first integer is the count of vowels, and the second integer is the count of consonants in each sentence.

Sample Input 0

2
I love programming.
Hello, World!
Sample Output 0

[(6, 10), (3, 7)]

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int>get_v(string s){
    int f = 0, t = 0;
    for(int i=0; i<s.size(); i++){
        if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i])== 'u'){
            f++;
        }else if(isalpha(s[i]))
            t++;
    }
    return make_pair(f, t);
}

int main() {
    vector<pair<int, int>>seen;
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string temp;
        getline(cin, temp);
        pair<int, int>re= get_v(temp);
        seen.push_back(re);
    }
    // pair<int, int>se = get_v(b);
    // seen.push_back(se);
    cout<<"[";
    for(const auto & i : seen){
        cout<<"(";
        cout<<i.first<<", "<<i.second;
        cout<<")";
        if (i.first != seen[seen.size()-1].first)
            cout<<", ";
    }
    cout<<"]";
    return 0;
}
