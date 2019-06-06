#include <iostream>
#include <vector>

using namespace std;

int insertionSort(vector <int> &vec, int N, int g){
  int cnt = 0;
  for(int i = g; i < N; i++){
    int j = i - g;
    int v = vec.at(i);
    while(j >= 0  && v < vec.at(j)){
      vec.at(j+g) = vec.at(j);
      j -= g;
      cnt++;
    }
    vec.at(j+g) = v;
  }
  return cnt;
}

int main(){
  int n; cin >> n;
  vector <int> A(n);
  for(int i = 0; i < n; i++){
    cin >> A.at(i);
  }

  int cnt = 0;
  int m = 0;
  int h = 1;
  vector <int> G;
  while(h <= n){
    G.push_back(h);
    h = 3*h + 1;
    m++;
  }

  for(int i = m-1; i >=0 ; i--){
    cnt += insertionSort(A,n,G[i]);
  }

  cout << m << endl;
  for(int i = m-1; i >=0; i--){
    cout << G.at(i);
    if(i != 0) cout << " ";
    else cout << endl;
  }
  cout << cnt << endl;
  for(int i = 0; i < n; i++){
    cout << A.at(i) << endl;
  }
  
}
