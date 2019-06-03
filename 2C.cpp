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
      if(vec[i][1] > vec[i+1][1]){
	swap(vec.at(i),vec.at(i+1));
	flag = true;
      }
    }
  }
}

void SelectionSort(vector <string> &vec, int N){
  for(int i = 0; i < N-1; i++){
    min_j = i;
    bool flag = false;
    for(int j = i; j < N; j++){
      if(vec[j][1] < vec[min_j][1]){
	min_j = j;
	flag = true;
      }
    }
    if(flag) swap(vec[i],vec[min_j]);
  }
}

int judge(vector <string> vec, )
int main(){
  
}
