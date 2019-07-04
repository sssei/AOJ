#include <iostream>
#include <string>
#include <vector>
#define MAX 100000
#define NIL -1
using namespace std;

int D[MAX];

struct Node{
  int parent, left, right;
};

Node T[MAX];

void setDepth(int u,int p){
  D[u] = p;
  if(T[u].right != NIL){
    setDepth(T[u].right, p);
  }
  if(T[u].left != NIL){
    setDepth(T[u].left, p+1);
  }
}


void printChildren(int u, vector<int> &C){
  int c = T[u].left;
  while(c != NIL){
    C.push_back(c);
    c = T[c].right;
  }
}

int main(){
  int n; cin >> n;
  int k;

  for(int i = 0; i < n; i++){
    T[i].parent = NIL;
  }
  
  for(int i = 0; i < n; i++){
    int idx; 
    cin >> idx;
    cin >> k;
    if(k){
      vector<int> C(k);
      for(int j = 0; j < k; j++){
	cin >> C[j];
	T[C[j]].parent = i;
      }
      T[i].left = C[0];
      for(int j = 0; j < k-1; j++){
	T[C[j]].right = C[j+1];
      }     
      T[C[k-1]].right = NIL;
    }else{
      T[i].left = NIL;
    }
  }

  int u;
  for(int i = 0; i < n; i++){
    if(T[i].parent == NIL){
      u = i;
      break;
    }
  } 
  setDepth(u, 0);
  cout << u << endl;
  /*  for(int i = 0; i < n; i++){
    cout << "node " << i ;
    cout << ": parent = " << T[i].parent;
    cout << ", depth = " << D[i] << ", ";
    if(i == u){
      cout << "root, ";
    }else if(T[i].left == NIL){
      cout << "leaf, ";
    }else{
      cout << "internal node, ";
    }
    cout << "[";
    vector<int> C;
    printChildren(i,C);
    for(int j = 0; j < (int)C.size(); j++){
      if(j) cout << ", ";
      cout << C[j];
    }
    cout << "]" << endl;
  }
  */
}
