/*Given a directed graph with two vertices ( source and
destination). Design an algorithm and implement it using a
program to find the weight of the shortest path from source to
destination with exactly k edges on the path.*/

#include <iostream>
#include <vector>
using namespace std;
int shortestpath(vector<vector<int>> &graph , int n , int src , int dest , int k){
    vector<vector<int>> dp(k+1,vector<int>(n,INT_MAX));
    for(int e  = 1 ; e < k ; e++){
        for(int u = 0 ; u < n ; u++){
            for(int v = 0 ; v < n ; v++){
                if(graph[u][v]!=0 && dp[e-1][u] != INT_MAX){
                    dp[e][v] = min(dp[e][v],graph[u][v]+dp[e-1][u]);
                }
            }
        }
    }
    if(dp[k][dest-1]==INT_MAX){
        return -1;
    }
    return dp[k][dest-1];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>graph[i][j];
        }
    }
    int src, dest;
    cin>>src>>dest;
    int k;
    cin>>k;
    int ans = shortestpath(graph,n,src,dest,k);
    if(ans==-1){
        cout<<"Path not found";

    }
    else{
        cout<<"Shortest path from" <<src <<"to"<<dest<<"is"<<ans<<endl;
    }

}
