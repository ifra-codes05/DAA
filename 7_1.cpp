/*After end term examination, Akshay wants to party with his
friends. All his friends are living as paying guest and it has been
decided to first gather at Akshay’s house and then move towards
party location. The problem is that no one knows the exact
address of his house in the city. Akshay as a computer science*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

void printpath(vector<int> &parent , int v){
    if(v==-1) return;
    printpath(parent,parent[v]);
    cout<<v+1<<" ";
}
void dijkstra(vector<vector<int>>&graph , int n , int src){
    vector<int> dist(n, INT_MAX);
    vector<int> vis(n, 0);
    vector<int> parent(n, -1);
    dist[src] = 0;
    for(int i = 0 ; i < n ; i++){
        int u = -1;
        for(int j = 0 ; j < n ; j++){
            if(!vis[j]&&(u==-1 || dist[u]>dist[j])){
                u = j;
            }
        }
        if(u==-1) return;
        vis[u] = 1;
        for(int v = 0 ; v < n ; v++){
            if(graph[u][v]!=0 && !vis[v]){
                if(dist[u]+graph[u][v]<dist[v]){
                    dist[v] = graph[u][v] + dist[u];
                    parent[v]=u;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(i==src){
            cout<<src+1<<"0 :";
        }
        else if(dist[i]!=INT_MAX){
            printpath(parent,i);
            cout<<": "<<dist[i]<<endl;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>graph[i][j];

        }
    }
    int src;
    cin>>src;
    src--;

    dijkstra(graph,n,src);
}
