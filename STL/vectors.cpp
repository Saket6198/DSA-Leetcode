#include<iostream>
#include<vector>
#include<algorithm>

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
    a3.insert(a3.begin() + 1, 50); // used to insert elements at particular position.
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

    a3.erase(a3.begin() + 1);  // can be used to remove elements at specific location 
    // O(n), after erasing all the elements in front are shifted one step back to occupy the erased elements position

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

a5.rbegin(); // Returns a read/write reverse iterator that points to the last element in the %vector. Iteration is done in reverse element order.

a5.rend(); // Returns a read/write reverse iterator that points to one before the first element in the %vector. Iteration is done in reverse element order.
for(auto it = a5.begin(); it != a5.end(); it++){
    cout<<*it<<" ";
}
// OR
for(int i=0; i<a5.size(); i++){
    cout<<a5[i]<<" ";
}

cout<<a5.size();
cout<<a5.capacity();

/* Sorting */

vector<int>a6={2, 3, 1, 7, 4, 4};
sort(a6.begin(), a6.end()); // sort in increasing order
cout<<"\n A6 \n";
for(auto it : a6){
    cout<<it<<" ";
}
sort(a6.begin(), a6.end(), greater<int>()); // sort in decreasing order
// OR
sort(a3.rbegin(), a3.rend());
cout<<endl;
for(auto it : a6){
    cout<<it<<" ";
}

/* SEARCHING IN VECTOR */
cout<<endl;
cout<<binary_search(a6.begin(), a6.end(), 1)<<endl;  //returns 1 if found otherwise returns 0

//int lower = lower_bound()
cout<<"searching";
cout<<find(a6.begin(), a6.end(), 88) - a6.begin()<<endl<<a6.size()<<endl; // used to find the exact index position of an element
// If the value is found in the sequence, the iterator to its position is returned.
// If the value is not found, the iterator to the last position is returned.  

vector<int>a7 = {4, 1,7, 8, 4, 4, 9, 4};
auto counter = count(a7.begin(), a7.end(), 4); // count returns the no of times a element occured in the vector
cout<<counter<<endl;
auto maxi = max_element(a7.begin(), a7.end()); //it is also a iterator that returns the maximum element present in the vector
cout<<*maxi<<endl;
auto mini = min_element(a7.begin(), a7.end());
cout<<*mini;



}
