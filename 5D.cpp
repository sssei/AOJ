#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++) cin >> A.at(i);
  int m = *max_element(A.begin(), A.end());
  vector<int> C(m+1,0);
  for(int i = 0; i < n; i++) C.at(A.at(i))++;
  for(int i = 1; i < MAX; i++) C.at(i) += C.at(i-1);

  int cnt = 0;
  for(int i = 0; i < 10; i++){
    cout << " " << C.at(i);
  }
  cout << endl;
  for(int i = 0; i < n; i++){
    int t = A.at(i);
    if(C.at(t) - 1 < i){
      cnt += i - C.at(i) + 1;
    }
  }
  cout << cnt << endl;
  
}
