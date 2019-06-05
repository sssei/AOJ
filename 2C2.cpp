#include <iostream>
#include <string>
#include <vector>

using namespace std;



void bubble(vector <string> &A, int N){
  for(int i = 0; i < N; i++){
    for (int j = N-1; j >= i + 1; j--){
      if(A[j][1] < A[j -1][1]){
	string t  = A[j];
	A[j] = A[j-1];
	A[j-1] = t;
      }
    }
  }
}

void selection(vector <string> &A, int N){
  for (int i = 0; i < N; i++){
    int min_j = i;
    for (int j = i; j < N; j++){
      if(A[j][1] < A[min_j][1]) min_j = j;
    }
    string t = A[i];
    A[i] = A[min_j];
    A[min_j] = t;
  }
}

void print(vector <string> A, int N){
  for (int i = 0; i < N; i++){
      if(i > 0) cout << " ";
      cout << A[i];
  }
  cout << endl;
}


int main(){
  
  int N; cin >> N;
  vector <string> C1(N),C2(N);

  for (int i = 0; i < N; i++){
    cin >> C1[i];
  }

  C2 = C1;

  bubble(C1,N);
  selection(C2,N);

  print(C1,N);
  cout << "Stable" << endl;
  print(C2,N);
  if(C1 == C2){
    cout << "Stable" << endl;
  }else{
    cout << "Not stable" << endl;
  }

  return 0;
}
