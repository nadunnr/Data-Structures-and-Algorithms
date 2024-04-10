#include <bits/stdc++.h>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> adj_matrix, int start){

    int n = adj_matrix.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    cout<<start<<endl;
    visited[start] = true;

    while(!q.empty()){
        for (int i=0; i<n; i++){
            if(adj_matrix[q.front()][i] != 0 and visited[i]==false){
                q.push(i);
                visited[i] = true;
                cout<<i<<endl;
            }
        }
        q.pop();
    }
}

int main(){
    //a demonstration graph
    vector<vector<int>>graph = {{0,1,1,0},{1,0,1,1},{1,1,0,0},{0,1,0,0}};
    bfs(graph,3);
}