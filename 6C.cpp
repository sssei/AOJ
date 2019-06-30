#include <iostream>
#include <string>
#include <utility>

using namespace std;

int partition(int A[], int p, int r){
  int x = A[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(A[j] <= x){
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i+1;
}

void quickSort(int A[], int p, int r){
  if(p < r){
    int q = partition()
  }
}

int main(){
  
  
}
