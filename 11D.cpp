#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const int NIL = -1;
static const int MAX = 100000;
int colors[MAX];
vector<int> G[MAX];

int n,m;

void dfs(int r, int c){
  stack<int> st;
  st.push(r);
  colors[r] = c;
  while(!st.empty()){
    int u = st.top();
    st.pop();
    for(auto x: G[u]){
      if(colors[x] == NIL){
	st.push(x);
	colors[x] = c;
      }
    }
  }
}

void assignColor(){
  int id = 1;
  for(int i = 0; i < n; ++i) colors[i] = NIL;
  for(int i = 0; i < n; ++i){
    if(colors[i] == NIL) dfs(i, id++);
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    int s,t;
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  assignColor();
  int q; cin >> q;
  for(int i = 0; i < q; ++i){
    int s,t;
    cin >> s >> t;
    if(colors[s] == colors[t]) cout << "yes" << endl;
    else cout << "no" << endl; 
  }
}
