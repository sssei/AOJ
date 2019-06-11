#include <iostream>
#include <vector>
#include <utility>
#define LEN 100

using namespace std;

typedef struct P{
  string p;
  int n;
}pt;

class Q{
private:
  vector<> vec(LEN);
  int top;
  int tail;
public:
  void enqueue(){
    vec.at(tail) = 
    tail++;
  }
}



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n,q; cin >> n >> q;
  vector < pair<string,int> > vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec[i].first >> vec[i].second;
  }

  int t = 0;
  while(!vec.empty()){
    for(int i = 0; i < vec.size(); i++){
      if(vec[i].second > q){
	vec[i].second -= q;
	t += q;
      }else{
	t += vec[i].second;
	cout << vec[i].first << " " << t << endl;
	vec.erase(vec.begin() + i);
	i--;
      }
    }
  }
}
