#include <iostream>
#define MAX 25
#define NIL -1
using namespace std;

struct Node{
  int parent, left, right;
};

Node T[MAX];

void init(int n){
  for(int i = 0; i < n; i++){
    T[i].parent = NIL;
  }
  for(int i = 0; i < n; i++){
    T[T[i].right].parent = i;
    T[T[i].left].parent = i;
  }
}

void preorder(int id){
  cout << " " << id;
  if(T[id].left != NIL){
    preorder(T[id].left);
  }
  if(T[id].right != NIL){
    preorder(T[id].right);
  }
}

void inorder(int id){
  if(T[id].left != NIL){
    inorder(T[id].left);
  }
  cout << " " << id;
  if(T[id].right != NIL){
    inorder(T[id].right);
  }
}

void postorder(int id){
  if(T[id].left != NIL){
    postorder(T[id].left);
  }
  if(T[id].right != NIL){
    postorder(T[id].right);
  }
  cout << " " << id;
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
    if(T[i].parent == NIL) u = i;
  }

  cout << "Preorder" << endl;
  preorder(u);
  cout << endl;
  cout << " Inorder" << endl;
  inorder(u);
  cout << endl;
  cout << "Postorder" << endl;
  postorder(u);
  cout << endl;
}
