/*Assume that a project of road construction to connect some
cities is given to your friend. Map of these cities and roads
which will connect them (after construction) is provided to him
in the form of a graph. Certain amount of rupees is associated
with construction of each road. Your friend has to calculate the
minimum budget required for this project. The budget should be
designed in such a way that the cost of connecting the cities
should be minimum and number of roads required to connect all
the cities should be minimum (if there are N cities then only N-1
roads need to be constructed). He asks you for help. Now, you
have to help your friend by designing an algorithm which will
find minimum cost required to connect these cities. (use Prim's
algorithm)*/

#include<bits/stdc++.h>
using namespace std;

int primsalgo(vector<vector<int>>& graph, int V) {

    vector<int> key(V, INT_MAX);
    vector<bool> inmst(V, false);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    int src = 0;

    key[src] = 0;

    pq.push({0, src});

    int mstweight = 0;

    while(!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        if(inmst[u])
            continue;

        inmst[u] = true;

        mstweight += key[u];

        for(int v = 0; v < V; v++) {

            if(graph[u][v] != 0 &&
               !inmst[v] &&
               graph[u][v] < key[v]) {

                key[v] = graph[u][v];

                pq.push({key[v], v});
            }
        }
    }

    return mstweight;
}

int main() {

    int V;

    cout << "Enter V: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int mincost = primsalgo(graph, V);

    cout << "Minimum weight is " << mincost << endl;

    return 0;
}
