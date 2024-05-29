#include<iostream>
#include<vector>

using namespace std;

int main(){
    /* Initialisation methods :*/

    //vector<data-type>name(size, initialisation) 

    vector<int>a1(5); //fixed 5 size vector

    vector<int>a2(5, 2);  //initialised a vector of size 5 with all elements as 2

    vector<int>a3; // dynamically allocated vector

    a3.push_back(1); // only way to put elements into the vector
    a3.push_back(2); // every time it needs space the size of the vector is doubled
    a3.push_back(3); // so 1st opr had 1 size, 2nd opr had 2 size, 3rd opr had 4 size and so on..

    vector<int>a4 = {2, 4, 6, 8, 10}; // 
}
