#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void CountingSort(vector<int> A, vector<int> &B, int k){
  vector<int> C(k+1,0);
  int n = (int)A.size();
  for(int i = 0; i < n; i++){
    C.at(A.at(i))++;
  }
  for(int i = 1; i < k+1; i++){
    C.at(i) += C.at(i-1);
  }
  for(int i = n-1; i >= 0; i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
}

int main(){
  int n; cin >> n;
  vector<int> A(n),B(n);
  for(int i = 0; i < n; i++) cin >> A.at(i);
  int k = *max_element(A.begin(), A.end());
  CountingSort(A,B,k);
  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    cout << B.at(i);
  }
  cout << endl;
}
