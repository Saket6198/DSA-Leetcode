#include <iostream>
#include <vector>
using namespace std;

//directed (weighted) graph
int main(){
    int vertex, edges;
    cout<<"Enter the vertex and edges : ";
    cin>>vertex>>edges;
    vector<pair<int, int> >AdjList[vertex];

    int u, v, weight;
    for(int i=0; i<edges; i++){
        cout<<"enter the edges \n";
        cin>>u>>v>>weight;
        AdjList[u].push_back(make_pair(v, weight));
    }
     //Print the Adjlist
     for(int i=0; i<vertex; i++){
        cout<<i<<" ->";
        for(int j=0; j<AdjList[i].size(); j++){
            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<" ";

        }
        cout<<endl;

     }
}