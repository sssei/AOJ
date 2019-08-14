#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

void maxHeapify(vector<int>& A, int i){
  int l = 2 * (i + 1) - 1;
  int r = 2 * (i + 1);
  int H = A.size();
  int largest;
  if(l <= H && A[l] > A[i]){
    largest = l;
  }else{
    largest = i;
  }
  if(r <= H && A[largest] < A[r]){
    largest = r;
  }

  if(largest != i){
    swap(A[i], A[largest]);
    maxHeapify(A, largest);
  }
}

void buildMaxHeap(vector<int>& A){
  for(int i = (A.size()+1)/2-1; i >= 0; i--){
    maxHeapify(A,i);
  }
}

int main(){
  int H; cin >> H;
  vector<int> A(H);
  for(int i = 0; i < H; i++){
    cin >> A[i];
  }
  buildMaxHeap(A);
  for(int i = 0; i < H; i++){
    cout << " " << A[i];
  }
  cout << endl;
}
