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

void insert(vector<int>& A, int key){
  A.push_back(key);
  int i = A.size()-1;
  while(i > 0 && A[(i+1)/2-1] < A[i]){
    swap(A[(i+1)/2-1], A[i]);
    i = (i+1)/2 - 1;
  }
}

int extra(vector<int>& A){
  int max = A[0];
  A[0] = A.back();
  A.pop_back();
  maxHeapify(A,0);
  return max;
}

int main(){
  int key;
  string order;
  vector<int> A;
  while(1){
    cin >> order;
    if(order == "end") return 0;
    if(order == "insert"){
      cin >> key;
      insert(A,key);
    }else{
      key = extra(A);
      cout << key << endl;
    }
  }
}
