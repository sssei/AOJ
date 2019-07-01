#include <iostream>
#include <vector>

using namespace std;

void CountingSort(vector<int> A, vector<int> B, int k){
  vector<int> C(k,0);
  int n = (int)A.size();
  for(int i = 0; i < n; i++){
    C.at(A.at(i))++;
  }
  for(int i = 1; i < n; i++){
    C.at(i) += C.at(i-1);
  }
  

}
