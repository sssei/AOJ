#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
  int N,W;
  cin >> N >> W;
  vector< pair<int, int> > item(N+1);
  for(int i = 0; i < N; i++){
    cin >> item[i+1].first >> item[i+1].second;
  }
  int C[N+1][W+1];
  for(int i = 0; i < W+1; i++){
    C[0][i] = 0;
  }
  for(int i = 0; i < N+1; i++){
    C[i][0] = 0;
  }
  for(int i = 1; i < N + 1; i++){
    for(int j = 0; j < W + 1; j++){
      if(item[i].second <= j){
	C[i][j] = max(C[i-1][j], C[i-1][j-item[i].second] + item[i].first);
      }else{
	C[i][j] = C[i-1][j];
      }
    }
  }
  cout << C[N][W] << endl;
}
