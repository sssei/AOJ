#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n; cin >> n;
  int H[n];
  for(int i = 0; i < n; i++) cin >> H[i];
  for(int i = 0; i < n; i++){
    cout << "node " << i + 1 << ": key = " << H[i] << ", ";
    int parent = (i + 1) / 2;
    if(parent) cout << "parent key = " << H[parent-1] << ", ";
    if(2 * (i + 1) <= n) cout << "left key = " << H[2*(i+1)-1] << ", ";
    if(2 * (i + 1) + 1 <= n) cout << "right key = " << H[2*(i+1)] << ", ";
    cout << endl;
  }
  
}
