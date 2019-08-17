#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int main(){
  int n; cin >> n;
  vector< vector<int> > Adj(n,vector<int>(0));
  vector<int> d(n);
  vector<int> f(n);
  for(int i = 0; i < n; i++){
    int id; cin >> id;
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int tmp; cin >> tmp;
      Adj[i].push_back(tmp);
    }
  }

  while(1){
     
  }
}

