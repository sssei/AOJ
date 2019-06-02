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
  
}
  
int main(){
  
}
