#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX 100

enum color
{
 white;
 gray;
 black;
};

vector<color> visited(MAX);
int Adj[MAX][MAX];
ll dis[MAX];
ll p[MAX];
int n;

int dijkstra(int s){
  for(int i = 0; i < n; i++){
    visited[i] = white;
  }
  dis[s] = 0;
  while{
    for(int i = 0; i < n; i++){
      if(Adj[s])
    
	}
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    int u,k; cin >> u >> k;
    for(int j = 0; j < k; ++j){
      int v,c; cin >> v >> c;
      Adj[--u][--v] = c;
    }
  }

  
}
