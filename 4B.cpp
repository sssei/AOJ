#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> S(n);
  for(int i = 0; i < n; i++) cin >> S.at(i);
  int q; cin >> q;
  vector<int> T(q);
  for(int i = 0; i < q; i++) cin >> T.at(i);
  int cnt = 0;
  for(int i = 0; i < q; i++){
    int a = 0;
    int b = n;
    int c = (a+b)/2;
    while(a != c){
      if(T.at(i) < c){
	b = c;
	c = (a+b)/2;
      }else{
	a = c;
	c = (a+b)/2;
      }
      if(T.at(i) == S.at(c)){
	cnt++;
	break;
      }
    }
  }
  cout << cnt << endl;
}
