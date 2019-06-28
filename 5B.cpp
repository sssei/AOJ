#include <iostream>
#define INF 1e10

using namespace std;

int cnt = 0;

int merge(int A[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  long long  L[n1 + 1], R[n2 + 1];
  for(int i = 0; i < n1; i++) L[i] = A[left + i];
  for(int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = INF;
  R[n2] = INF;
  int j = 0, k = 0;
  for(int i = left; i < right; i++){
    if(R[j] <= L[k]){
      A[i] = R[j];
      j++;
    }else{
      A[i] = L[k];
      k++;
    }
  }
  return right - left;
}

void mergesort(int A[], int left, int right){
  if(right - left > 1){
    int mid = (right + left)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    cnt += merge(A, left, mid, right);
  }
}

int main(){
  int n; cin >> n;
  int A[n];
  for(int i = 0; i < n; i++) cin >> A[i];
  mergesort(A, 0, n);
  for(int i = 0; i < n; i++){
    if(i != 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
}
