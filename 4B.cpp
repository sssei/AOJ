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
    int left = 0;
    int right = n;
    int mid;
    while(left < right){
      mid = (left + right)/2;
      if(T.at(i) < S.at(mid)){
	right = mid;
      }else if(T.at(i) == S.at(mid)){
	cnt++;
	break;
      }else{
	left = mid + 1;
      }
    }
  }
  cout << cnt << endl;
}
