#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void Bubblesort(vector <string> &vec, int N){
  bool flag = true;
  while(flag){
    flag = false;
    for(int i = 0; i < N-1; i++){
      if((int)vec[i][1] > (int)vec[i+1][1]){
	swap(vec.at(i),vec.at(i+1));
	flag = true;
      }
    }
  }
}


void SelectionSort(vector <string> &vec, int N){
  for(int i = 0; i < N-1; i++){
    int min_j = i;
    bool flag = false;
    for(int j = i + 1; j < N; j++){
      if((int)vec[j][1] < (int)vec[min_j][1]){
	min_j = j;
	flag = true;
      }
    }
    if(flag) swap(vec[i],vec[min_j]);
  }
}


int main(){
  int N; cin >> N;
  vector <string> vec(N);
  for(int i = 0; i < N; i++){
    cin >> vec.at(i);
  }

  vector <string> vec2 = vec;
  Bubblesort(vec,N);
  for(int i = 0; i < N - 1; i++){
    cout << vec.at(i) << " ";
  }
  cout << vec.at(N-1) << endl;
  cout << "Stable" << endl;

  SelectionSort(vec2,N);
  for(int i = 0; i < N - 1; i++){
    cout << vec2.at(i) << " ";
  }
  cout << vec2.at(N-1) << endl;
  if(vec == vec2){
    cout << "Stable" << endl;
  }else{
    cout << "Not stable" << endl;
  }
}
