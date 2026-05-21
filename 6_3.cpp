/*Given a directed graph, design an algorithm and implement it
using a program to find whether cycle exists in the graph or not.*/

#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node , vector<vector<int>>&adj , vector<int> &vis , vector<int> &pathVis){
    vis[node] = 1;
    pathVis[node] = 1;
    for(int nbr : adj[node]){
        if(!vis[nbr]){
            if(dfs(nbr , adj , vis , pathVis)){
                return true ;
            }
        }
        else if(pathVis[nbr]){
            return true;
        }
    }
    return false;
}
int main(){
    int n ;
    cin>>n;
    vector<vector<int>>mat (n,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>adj(n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(mat[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    vector<int> vis(n,0) , pathVis(n,0);
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathVis)){
                cout<<"Cycle Exist";
                return 0;
            }
        }
    }
    cout<<"Cycle does not exist ";
    return 0;
}
