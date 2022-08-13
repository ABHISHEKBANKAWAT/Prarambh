// Undirected graph

#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  int adj[n+1][m+1];
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u][v] =1;
    // adj[u][v]=weight; for weighted graph
    adj[v][u] =1;

  }
  return 0;
}

// usign a adjacency list

#include<bits/stdc++.h>
using namespace std;
vector<int> adj[n+1];
for(int i = 0 ; i<m;i++){
  int u,v;
  cin>>u>>v;
  adj[u].push_back(v);
  //for weighted graph we will store in pairs (node,weight)
  adj[v].push_back(u);
}

