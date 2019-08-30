#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#define MAX 100
using namespace std;

enum color
{
 WHITE,
 GLAY,
 BLACK,
};

int n;
int d[MAX], f[MAX];
bool A[MAX][MAX];
int t = 0;
color color[MAX];

void dfs(int u){
  color[u] = GLAY;
  d[u] = ++t;
  for(int i = 0; i < n; ++i){
    if(A[u][i] && color[i] == WHITE){
      dfs(i);
    }
  }
  color[u] = BLACK;
  f[u] = ++t;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      A[i][j] = false;
    }
  }
                                   
  for(int i = 0; i < n; i++){
    int id; cin >> id;
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int tmp; cin >> tmp;
      A[id-1][tmp-1] = true;
    }
  }

  for(int i = 0; i < n; ++i){
    color[i] = WHITE;
  }

  for(int i = 0; i < n; ++i){
    if(color[i] == WHITE){
      dfs(i);
    }
  }
  for(int i = 0; i < n; ++i){
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }
}

