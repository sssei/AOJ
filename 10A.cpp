#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

vector<int> F = {1,1};

int fib(int n){
  int l = F.size();
  if(l >= n+1){
    return F[n];
  }
  if(n == 0 || n == 1){
      return F[n];
  }
  F.push_back(fib(n-1) + fib(n-2));
  return F[n];
}

int main(){
  int n;
  cin >> n;
  cout << fib(n) << endl;
}
