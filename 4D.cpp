#include <iostream>
#define MAX 100000
using namespace std;

typedef long long ll;

int n,k;
ll T[MAX];

int check(ll P){
  int i = 0;
  for(int j = 0; j < k; j++){
    ll s = 0;
    while(s + T[i] <= P){
      s += T[i];
      i++;
      if(i == n) return n;
    }
  }
  return i;
}

ll solve(){
  ll right = 10000 * 100000;
  ll left = 0;
  while(right - left > 1){
    ll mid = (right + left)/2;
    int v = check(mid);
    if(v >= n) right = mid;
    else left = mid;
  }
  return right;
}

int main(){
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> T[i];
  }
  ll ans = solve();
  cout << ans  << endl;
}
