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
    //also dynamically allocating size is allowed in vector and not in array since array is implemented in the stack part of RAM which has limited memory
    // while vector is located in the heap part of RAM which has very large size.

    // this doubling up of space allows the push_back() operation to be performed in O(1) time since if it increases size by 1, 
    // it will have to create space and link it up after each push-back operation which is not efficient.

    /* Deletion Method */

    a3.pop_back();  // Removes last element. This is a typical stack operation. It shrinks the %vector by one. 
    // Note that no data is returned, and if the last element's data is needed, it should be retrieved before pop_back() is called.
    // O(1);

    a4.clear(); // clears all value

    a3.erase(a3.begin() + 1); // O(n), after erasing all the elements in front are shifted one step back to occupy the erased elements position

    cout<<a2.front()<<endl; // returns 1st element
    cout<<a2.back()<<endl; // returns last element
    cout<<a3.empty()<<endl;  // returns 1 if begin and end iterator point to the same.
    cout<<a2.at(2)<<endl; /* Provides access to the data contained in the %vector.

Parameters:
n – The index of the element for which data should be accessed
*/


/* Iterator in vector */

vector<int>a5 = {4, 6, 8 ,10};
a5.begin(); // Returns a read/write iterator that points to the first element in the %vector. Iteration is done in ordinary element order.

a5.end(); // Returns a read/write iterator that points one past the last element in the %vector. Iteration is done in ordinary element order.

for(auto it = a5.begin(); it != a5.end(); it++){
    cout<<*it<<" ";
}
// OR
for(int i=0; i<a5.size(); i++){
    cout<<a5[i]<<" ";
}

}
