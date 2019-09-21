#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
typedef long long ll;
using namespace std;

enum color
  {
   WHITE,
   GLAY,
   BLACK,
  };

int main(){
  int n; cin >> n;
  vector<int> Adj[n];
  for(int i = 0; i < n; ++i){
    int u; cin >> u;
    int k; cin >> k;
    for(int i = 0; i < k; ++i){
      int v; cin >> v;
      Adj[u-1].push_back(v-1);
    }
  }
  queue<int> q;
  vector<color> colors(n, WHITE);
  vector<int> d(n);
  q.push(0);
  colors[0] = GLAY;
  while(!q.empty()){
    int u = q.top(); q.pop();
    for(auto x: Adj[u]){
      if(colors[x] == WHITE){
	q.push(x);
	d[x] = d[u] + 1;
	colors[x] = GLAY;
      }
    }
    colors[u] = BLACK;
  }

  for(int i = 0; i < n; ++i){
    cout << i << " " << d[i] << endl;
  }
}
 
