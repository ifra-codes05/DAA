/*Assume that same road construction project is given to another
person. The amount he will earn from this project is directly
proportional to the budget of the project. This person is greedy,
so he decided to maximize the budget by constructing those
roads who have highest construction cost. Design an algorithm*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mycmp(vector<int>&a , vector<int>&b){
    return a[2] > b[2];
}

int findparent(vector<int>&parent , int node ){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findparent(parent,parent[node]);
}

void unionSet(int u , int v , vector<int>&parent , vector<int>&rank){
    u = findparent(parent,u);
    v = findparent(parent,v);

    if(rank[u] < rank[v]){
        parent[u] = v;
        rank[v]++;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

void kruskal(int n , vector<vector<int>>&edges){
    vector<int> parent(n);
    vector<int> rank(n,0);

    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), mycmp);

    int ans = 0;

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(findparent(parent,u) != findparent(parent,v)){
            unionSet(u,v,parent,rank);
            ans += wt;
        }
    }

    cout << "Total min wt is : " << ans << endl;
}

vector<vector<int>> adjMat_to_liner(vector<vector<int>>&adjMat){
    vector<vector<int>> edges;

    for(int i = 0 ; i < adjMat.size() ; i++){
        for(int j = i+1 ; j < adjMat[i].size() ; j++){
            if(adjMat[i][j] != 0){
                edges.push_back({i,j,adjMat[i][j]});
            }
        }
    }

    return edges;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> adjMat(n,vector<int>(n));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> adjMat[i][j];
        }
    }

    vector<vector<int>> edges = adjMat_to_liner(adjMat);

    kruskal(n, edges);

    return 0;
}
