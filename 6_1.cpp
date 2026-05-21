/*Given a (directed/undirected) graph, design an algorithm and
implement it using a program to find if a path exists between
two given vertices or not. (Hint: use DFS)*/

#include<iostream>
#include<vector>
using namespace std;
bool dfs(vector<vector<int>>&adj , int src , int dest , vector<int> &vis){
    if(src==dest){
        return true;
    }
    vis[src] = 1;
    for(int i = 0 ; i < adj.size(); i++){
        if(!vis[i] && adj[src][i]==1){
            if(dfs(adj,i,dest,vis)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n ;
    cin>>n;
    vector<vector<int>> adj(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>adj[i][j];
        }
    }
    int src,dest;
    cin>>src>>dest;
    vector<int> vis(n,0);
    if(dfs(adj,src,dest,vis)){
        cout<<"Path exist";
    }
    else{
        cout<<"path does not exist ";
    }
}
