#include <iostream>
#include <vector>

using namespace std;
int A[20];

bool solve(int i, int m){
  if(m == 0) return true;
  if(i < 0) return false;
  bool res = solve(i - 1, m) || solve(i - 1, m - A[i]);
  return res;
}


int main(){
  int n,q;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
  cin >> q;
  vector<int> M(q);
  for(int i = 0; i < q; i++) cin >> M.at(i);
  for(int i = 0; i < q; i++){
    if(solve(n-1, M.at(i))) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
