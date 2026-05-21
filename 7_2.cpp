/*Design an algorithm and implement it using a program to solve
previous question's problem using Bellman- Ford's shortest path
algorithm.*/

#include <iostream>
#include <vector>
using namespace std;
void printpath(vector<int> &parent , int v){
    if(v==-1) return;
    printpath(parent,parent[v]);
    cout<<v+1<<" ";
}
void bellemford(vector<vector<int>>&graph , int n , int src){
    vector<int> dist(n,INT_MAX);
    vector<int> parent(n,-1);
    dist[src] = 0;
    for(int k = 0 ; k < n ; k++){
        for(int u = 0 ; u < n ; u++){
            for(int v = 0 ; v < n ; v++){
                if(graph[u][v]!= 0 && dist[u]!=INT_MAX){
                    if(dist[u]+graph[u][v]<dist[v]){
                        dist[v] = graph[u][v]+dist[u];
                        parent[v] = u;
                    }
                }
            }
        }
    }
    for(int u = 0 ; u < n ; u++){
        for(int v = 0 ; v < n ; v++){
            if(graph[u][v]!=0 && dist[u]!=INT_MAX){
                if(dist[u]+graph[u][v]<dist[v]){
                    cout<<"negative Cycle detect ";
                    return;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(i==src){
            cout<<src+1<<": 0"<<endl;
        }
        else if(dist[i]!=INT_MAX){
            printpath(parent,i);
            cout<<": "<<dist[i]<<endl;
        }
    }
}
int main(){
    int n ;
    cin>>n;

    vector<vector<int>> graph(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>graph[i][j];
        }
    }
    int src;
    cin>>src;
    src--;
    bellemford(graph,n,src);
    return 0;
}
