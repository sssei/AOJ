#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main(){
  vector <int> vec(10);
  iota(vec.begin(),vec.end(),1);
  vec.erase(vec.begin() + 1);
  for (int i = 0; i < 9; i++){
    cout << vec.at(i) << endl;
  }

}
