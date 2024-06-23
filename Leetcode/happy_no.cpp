#include<iostream>
using namespace std;

class Solution{
public:
    bool isHappy(int n){
        int fast = n;
        int slow = n; // initially slow and fast pointer are equal
        do{
            slow = square(slow);
            fast = square(square(fast)); 
        } while(slow != fast);
        return slow == 1;
    }
    int square(int num){
        int rem, ans = 0;
        while (num != 0){
            rem = num % 10;
            ans = rem * rem;
            num /= 10;
        }
        return ans;
    }
};

/* Using unordered_map  */

/*
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool>seen;
        int sum =0, rem, no = n;
        while(n != 1){
            no = n;
            while(no){
                rem = no % 10;
                sum += rem*rem;
                no = no / 10;
            }
            if(seen[sum] == 1)
                    return 0;
            seen[sum] = 1;
            n =sum;
            sum = 0;
        }
        return 1;
    }
};
*/
int main(){
    Solution solution; //creating an object of the class Solution in the main function to use the functions inside the solutions class.
    int no;
    cout<<"Enter the number"<<endl;
    cin>>no;
    bool result = solution.isHappy(no);
    if(result)
        cout<<no<<" is a happy no";
    else
        cout<<no<< " is not a happy no";
    return 0;
}