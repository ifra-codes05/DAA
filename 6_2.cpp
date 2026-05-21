/*Given a graph, design an algorithm and implement it using a
program to find if a graph is bipartite or not. (Hint: use BFS)*/

#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node , int col , vector<int>&colour , vector<vector<int>>&adj ){
    colour[node] = col;
    for(int nbr : adj[node]){
        if(colour[nbr] == -1){
            if (dfs(nbr,!col,colour,adj))
            {
                return true;
            }
            
        }
        else if(colour[node] == col){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> adj(n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(mat[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    vector<int> colour(n,-1);
    for(int i = 0 ; i < n ; i++){
        if(colour[i]==-1){
            if(dfs(i,0,colour,adj)){
                cout<<" Not Bipartite";
                return 0;
            }
        }
    }
    cout<<" Bipartite ";
    return 0;
}
