/* 68. Text Justification
Solved
Hard
Topics
premium lock icon
Companies
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth

*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int wordsLine(vector<string>& words, int& seen, int maxWidth) {
        int len = 0;
        int i = seen;
        while (i < words.size()) {
            int nextLen = len + (len == 0 ? 0 : 1) + words[i].size();
            if (nextLen > maxWidth) break;
            len = nextLen;
            i++;
        }
        return i - 1;
    }

    string justifyLine(vector<string>& words, int start, int end, int maxWidth, bool isLastLine) {
        int numWords = end - start + 1;
        int totalChars = 0;
        // o(n) cnt totalchars
        for (int i = start; i <= end; ++i) {
            totalChars += words[i].size();
        }

        int totalSpaces = maxWidth - totalChars;
        string line;

        if (isLastLine || numWords == 1) {  // if last line or only single word in a line then rest just put space
            for (int i = start; i <= end; ++i) {
                line += words[i];
                if (i != end) line += " ";
            }
            line += string(maxWidth - line.size(), ' ');    // adding space since it is the last line till maxWidth
        } else {
            int gaps = numWords - 1;    // normal gaps b/w words
            int spacePerGap = totalSpaces / gaps;   // space beside normal space distribution
            int extraSpaces = totalSpaces % gaps;

            for (int i = start; i < end; ++i) {
                line += words[i];
                int spacesToAdd = spacePerGap + (i - start < extraSpaces ? 1 : 0);
                line += string(spacesToAdd, ' ');
            }
            line += words[end];
        }

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int seen = 0;

        while (seen < words.size()) {
            int end = wordsLine(words, seen, maxWidth);
            bool isLastLine = (end == words.size() - 1);
            string justified = justifyLine(words, seen, end, maxWidth, isLastLine);
            ans.push_back(justified);
            seen = end + 1;
        }

        return ans;
    }
};


