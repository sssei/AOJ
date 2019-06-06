#include <iostream>
#include <string>

using namespace std;

class operand{
public:
  int one;
  int two;
  void calculate(string op){
    int result;
    if(op == "+") result = one + two;
    if(op == "*") result = one * two;
    if(op == "-") result = one - two;
    one = result;
  }
};

int main(){
  operand obj;
  string ope;
  cin >> obj.one;
  cin >> obj.two;
  cin >> ope;
  obj.calculate(ope);
}
