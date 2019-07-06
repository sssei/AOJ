#include <algorithm>
#include <iostream>
#include <string>

#define MAX 25
#define NIL -1 
using namespace std;

struct Node{
  int parent, left, right, sibling, degree;
  string type;
};

int D[MAX];
int H[MAX];
Node T[MAX];

void setDepth(int u, int d){
  D[u] = d;
  if(T[u].right != NIL){
    setDepth(T[u].right, d+1);
  }
  if(T[u].left != NIL){
    setDepth(T[u].left, d+1);
  }
}

int setHeight(int u){
  int h1 = 0, h2 = 0;
  if(T[u].right != NIL){
    h1 = setHeight(T[u].right) + 1;
  }
  if(T[u].left != NIL){
    h2 = setHeight(T[u].left) + 1;
  }
  return H[u] = max(h1, h2);
}

void printNode(int id){
  cout <<"node " << id << ": parent = " << T[id].parent;
  cout << ", sibling = " << T[id].sibling << ", degree = ";
  cout << T[id].degree << ", depth = " << D[id] << ", height = ";
  cout << H[id] << ", " << T[id].type << endl;
}

void init(int n){
  for(int i = 0; i < n; i++){
    T[i].parent = NIL;
    T[i].sibling = NIL;
  }
  
  for(int i = 0; i < n; i++){
    T[T[i].right].parent = i;
    T[T[i].left].parent = i;
  }

  for(int i = 0; i < n; i++){
    if(T[i].right != NIL && T[i].left != NIL){
      T[T[i].right].sibling = T[i].left;
      T[T[i].left].sibling = T[i].right;
    }
  }

  for(int i = 0; i < n; i++){
    if(T[i].right != NIL && T[i].left != NIL) T[i].degree = 2;
    else if(T[i].right == NIL && T[i].left == NIL) T[i].degree = 0;
    else T[i].degree = 1;
  }

  for(int i = 0; i < n; i++){
    if(T[i].parent == NIL) T[i].type = "root";
    else if(T[i].degree == 0) T[i].type = "leaf";
    else T[i].type = "internal node";
  }
}

int main(){
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int id; cin >> id;
    cin >> T[id].left >> T[id].right;
  }
  
  init(n);
  
  int u;
  for(int i = 0; i < n; i++){
    if(T[i].parent == -1){
      u = i;
      break;
    }
    if(i == n-1){
      cout << "Error" << endl;
      goto LAST;
    }
  }

  setDepth(u, 0);
  setHeight(u);
  init(n);
  for(int i = 0; i < n; i++){
    printNode(i);
  }
  
 LAST:;
}
