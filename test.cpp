#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int l;
  vector <int> vec;
  int i = 0;
  while(cin >> l){
    vec.push_back(l);
    cout << vec.at(i) << endl;
    i++;
  }
}
