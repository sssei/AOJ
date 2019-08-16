#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#define MAX 10000

using namespace std;

int c[MAX][MAX];

void lcs(string x, string y){
  int m = x.length();
  int n = y.length();
  for(int i = 0; i <= m; i++) c[i][0] = 0;
  for(int i = 0; i <= n; i++) c[0][i] = 0;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(x[i-1] == y[j-1]) c[i][j] = c[i-1][j-1] + 1;
      else if(c[i][j-1] > c[i-1][j]) c[i][j] = c[i][j-1];
      else c[i][j] = c[i-1][j];
    }
  }
}

int main(){
  int q; cin >> q;
  vector<string> X(q), Y(q);
  for(int i = 0; i < q; i++){
    cin >> X[i] >> Y[i];
  }
  for(int i = 0; i < q; i++){
    lcs(X[i], Y[i]);
    cout << c[X[i].size()][Y[i].size()] << endl;
  }
}
