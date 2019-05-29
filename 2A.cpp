#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N; cin >> N;
  vector <int> vec(N);
  for(int i = 0; i < N; i++){
    cin >> vec.at(i);
  }

  bool flag = true;
  int cnt = 0;
  
  while(flag){
    flag = false;
    for(int j = N-1; j > 0; j-- ){
      if(vec.at(j) < vec.at(j-1)){
	int temp = vec.at(j);
	vec.at(j) = vec.at(j-1);
	vec.at(j-1) = temp;
	cnt++;
	flag = true;
      }
    }
  }

  for(int i = 0; i < N - 1; i++){
    cout << vec.at(i) << " ";
  }
  cout << vec.at(N-1) << endl;
  cout << cnt << endl;
  
}
