#include <iostream>
#include <string>
#include <vector>

using namespace std;

class operand{
private:
  vector <int> vec;  
public:
  void calculate(string op){
    int result;
    bool flag = true;
    if(op == "+"){
      result = *(vec.end()-2) + *(vec.end()-1);
    }else if(op == "*"){
      result = *(vec.end()-2) * *(vec.end()-1);
    }else if(op == "-"){
      result = *(vec.end()-2) - *(vec.end()-1);
    }else{
      vec.push_back(stoi(op));
      flag = false;
    }
    if(flag){
      vec.pop_back();
      vec.back() = result;
    }
  }

  void get(){
    cout << vec.at(0) << endl;
  }
};

int main(){
  operand obj;
  string arg;
  while(cin >> arg){
    obj.calculate(arg);
  }
  obj.get();
}
