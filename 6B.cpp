#include <iostream>
#include <utility>

using namespace std;

int partition(int A[], int p, int r){
  int x = A[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(A[j] <= x){
      i++;
      swap(A[i],A[j])
    }
  }
}



