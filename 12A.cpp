#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const int INF = 10000;
static const int MAX = 100;

enum color
  {
   WHITE,
   GRAY,
   BLACK,
  };

int M[MAX][MAX];
color colors[MAX];
int d[MAX];
int p[MAX];
int n;
int ans = 0;
int cnt = 0;

void prim(){
  for(int i = 0; i < n; ++i){
    d[i] = INF;
    colors[i] = WHITE;
  }
  d[0] = 0;
  p[0] = -1;

  while(1){
    int minCost = INF;
    int u;
    for(int i = 0; i < n; ++i){
      if(colors[i] != BLACK && d[i] < minCost){
	minCost = d[i];
	u = i;
      }
    }
    if(minCost == INF) break;
    colors[u] = BLACK;
    for(int i = 0; i < n; ++i){
      if(M[u][i] != -1 && colors[i] != BLACK){
	if(M[u][i] < d[i]){
	  d[i] = M[u][i];
	  colors[i] = GRAY;
	  p[i] = u;
	}
      }
    }
  }
  for(int i = 0; i < n; ++i){
    if(p[i] != -1) ans += M[i][p[i]];
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> M[i][j];
    }
  }
  prim();
  cout << ans << endl;
  
}
