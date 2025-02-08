#include<bits/stdc++.h>
using namespace std;

class NumberContainers {
    public:
        NumberContainers() {
            
        }
        unordered_map<int, int>idx; // storing index as key and value as number
        unordered_map<int, set<int>>no; // storing number as key and index as {set} values
        void change(int index, int number) {
            if(idx.count(index) > 0){   // if a number is already present at the index in the map
                unsigned old = idx[index];  // if yes then we will first get the number to get the id in the no map to delete it
                no[old].erase(index);   // then we will delete the index from the set of the number
            }
            idx[index] = number;    // otherwise we simply update the index with the new number
            no[number].insert(index);   //same with the set
        }
        
        int find(int number) {
            if(no.count(number) != 0 && !no[number].empty())    // we will check if the number is present in the map_set and also check if its empty or not(imp since erase will give count 0 but should actually return -1)
                return *no[number].begin(); // else return the first element of the set
            return -1;
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */