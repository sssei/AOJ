#include <iostream>
#include <string>
#include <utility>

using namespace std;

int partition(pair<int, string> A[], int p, int r){
  int x = A[r].first;
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(A[j].first <= x){
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i+1;
}

void quickSort(pair<int, string> A[], int p, int r){
  if(p < r){
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

int main(){
  int n; cin >> n;
  pair<int, string> A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i].second >> A[i].first;
  }
  quickSort(A,0,n-1);
  for(int i = 0; i < n; i++){
    cout << A[i].second << " " << A[i].first << endl;
  }
}
