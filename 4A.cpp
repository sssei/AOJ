#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> S(n);
  for(int i = 0; i < n; i++){
    cin >> S.at(i);
  }
  int q;
  cin >> q;
  vector<int> T(q);
  for(int i = 0; i < q; i++){
    cin >> T.at(i);
  }
  int c = 0;
  for(int i = 0; i < q; i++){
    bool flag = false;
    for(int j = 0; j < n; j++){
      if(T.at(i) == S.at(j)){
	flag = true;
      }
    }
    if(flag) c++;
  }
  cout << c << endl;
}
