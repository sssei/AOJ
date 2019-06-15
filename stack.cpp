#include <iostream>
#include <stack>
using namespace std;

int main(){
  stack<int> S;
  S.push(3);
  S.push(3);
  S.push(6);
  cout << S.size() << endl;
  cout << S.top() << endl;
  S.pop();
  cout << S.top() << endl;
}
