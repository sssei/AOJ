#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
const int N = 100;

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> p(n+1);
  for(int i = 0; i < n; i++){
    cin >> p[i] >> p[i+1];
  }
  int M[N+1][N+1];
  for(int i = 1; i <= N; i++) M[i][i] = 0;
  for(int l = 2; l <= N; l++){
    for(int i = 1; i <= N-l+1; i++){
      int j = i + l - 1;
      int minM = M[i][i] + M[i + 1][j] + p[i - 1] * p[i] * p[j];
      for(int k = i; k < j; k++){
	minM = min(minM, M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j]);
      }
      M[i][j] = minM;
    }
  }
  cout << M[1][n] << endl;
}
