 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int main(){
  int n; cin >> n;
  vector< vector<int> >  Adj(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    int u; cin >> u;
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int v; cin >> v;
      Adj[u-1][v-1] = 1;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j) cout << " ";
      cout << Adj[i][j];
    }
    cout << endl;
  }
}
