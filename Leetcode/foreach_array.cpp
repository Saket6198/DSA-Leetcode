#include <iostream>
using namespace std;

int main() {
  int n;
  cout<<"enter size of array : ";
  cin>>n;
  int myNumbers[n];
  for (int i=0; i<n; i++){
    cin >> myNumbers[i];
  }
  for(int j : myNumbers)
    cout<<j;
}
