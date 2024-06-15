#include <iostream>
using namespace std;

int main() {
  int n;
  cout<<"enter size of array : ";
  cin>>n;
  int myNumbers[n];
  for (auto i : myNumbers){
    cin >> i;
  }
  for(int j : myNumbers)
    cout<<j<<" ";
}
