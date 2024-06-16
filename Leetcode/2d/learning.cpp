#include<iostream>

using namespace std;

void printarray(int arr[][4], int row, int col){ // passing col is necessary address calculation formula is = base_address + index( i.e. row_index * col + col_index) * col_indxe
    for(int row=0; row < 3; row++){
        for(int col=0; col<4; col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
}
bool findArray(int arr[][4], int row, int col, int target){
    for(int r=0; r < row; r++){
        for(int c=0; c<col; c++){
            if(arr[r][c] == target){
                return 1;
            }
        }
    }
    return 0;    
}
void AddMatrices(int arr1[][], int arr2[][]){
    int arr
}

int main(){
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // cout<<endl<<"ROW TYPE"<<endl;
    // for(int row=0; row < 3; row++){
    //     for(int col=0; col<4; col++){
    //         cout<<arr[row][col]<<" ";
    //     }
    // }
    // cout<<endl<<"2D TYPE"<<endl;
    
    //   for(int row=0; row < 3; row++){
    //      for(int col=0; col<4; col++){
//             cout<<arr[row][col]<<" ";
    //     }
    //     cout<<endl;
    // }
    printarray(arr, 3, 4);
    cout<<endl<<findArray(arr, 4, 3, 9);
    cout<<endl<<
}