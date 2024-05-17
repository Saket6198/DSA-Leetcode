#include <iostream>
#include <vector>
using namespace std;

// adjacency matrix
// directed and unweighted graph

int main(){
    int vertex,edges;
    printf("Enter no of vertex and edges: \n");
    cin>>vertex>>edges;
    vector<vector<bool> >AdjMat(vertex, vector<bool>(vertex, 0));


    int u, v;
     printf("Enter the edges present between vertices\n");
    for(int i=0; i<edges; i++){ //tells which edges are present like 0-1, 0-3, 2-3 etc.
       
        cin>>u>>v;
        AdjMat[u][v] = 1;
    }
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;

    }
}