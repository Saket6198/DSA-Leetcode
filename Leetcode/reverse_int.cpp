#include<iostream>
#include <climits>
using namespace std;

class Solution{
    public:
        int reverse(int x){
            int rem, ans = 0;
            while(x){
                rem = x % 10;
                if(ans > INT_MAX/10 || ans < INT_MIN/10)
                    return 0;
                ans = ans * 10 + rem;
                x /= 10;          
            }
            return ans;
        }
};
int main(){
    Solution solution;
    int no;
    cout<<"Enter the number \n";
    cin>>no;
    int result = solution.reverse(no);
    cout<<no<<" == " <<result;
    return 0;
}