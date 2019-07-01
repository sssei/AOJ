#include <iostream>
#include <string>
#include <utility>
#define INF 1e9
using namespace std;
bool flag2 = false;

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

int merge(pair<int, string> A[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  pair<int, string>  L[n1 + 1], R[n2 + 1];
  for(int i = 0; i < n1; i++) L[i] = A[left + i];
  for(int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = {INF, ""};
  R[n2] = {INF, ""};
  int j = 0, k = 0;
  for(int i = left; i < right; i++){
    if(R[j].first < L[k].first){
      A[i] = R[j];
      j++;
    }else{
      A[i] = L[k];
      k++;
    }
  }
  return right - left;
}

void mergesort(pair<int, string> A[], int left, int right){
  if(right - left > 1){
    int mid = (right + left)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A,left,mid,right);
  }
}


int main(){
  int n; cin >> n;
  pair<int, string> A[n],B[n];
  for(int i = 0; i < n; i++){
    cin >> A[i].second >> A[i].first;
    B[i] = A[i];
  }
  quickSort(A,0,n-1);
  mergesort(B,0,n);
  bool flag = true;
  for(int i = 0; i < n; i++){
    if(A[i] != B[i]){
      cout << "Not stable" << endl;
      flag = false;
      break;
    }
  }
  if(flag) cout << "Stable" << endl;  
  for(int i = 0; i < n; i++){
    cout << A[i].second << " " << A[i].first << endl;
  }
}
