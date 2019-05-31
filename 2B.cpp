#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector <int> vec(N);
  int cnt = 0;

  for(int i = 0; i < N; i++){
    cin >> vec.at(i);
  }

  for(int i = 0; i < N-1; i++){
    int min_v = i;
    bool flag = false;
    for(int j = i + 1; j < N; j++){
      if(vec.at(min_v) > vec.at(j)){
	min_v = j;
	flag = true;
      }
    }
    if(flag){
      swap(vec.at(i),vec.at(min_v));
      cnt++;
    }
  }

  for(int i = 0; i < N - 1; i++){
    cout << vec.at(i) << " ";
  }
  cout << vec.at(N-1) << endl;
  cout << cnt << endl;
}
