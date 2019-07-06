#include <string>
#include <iostream>

using namespace std;

struct Node{
  int key;
  Node *parent, *left, *right;
};

Node* NIL;
Node* T = NIL;

void insert(Node *z){
  Node *y = NIL;
  Node *x = T;
  while(x != NIL){
    y = x;
    if(z->key < x->key) x = x->left;
    else x = x->right;
  }
  z->parent = y;

  if(y == NIL){
    T = z;
  }else if(z->key < y->key){
    y->left = z;
  }else{
    y->right = z;
  }
}

void inorder(Node *u){
  if(u == NIL) return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node *u){
  if(u == NIL) return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main(){
  int m; cin >> m;
  for(int i = 0; i < m; i++){
    string order;
    cin >> order;
    if(order[0] == 'i'){
      int key; cin >> key;
      Node* p = new Node;
      p->key = key;
      p->parent = NIL;
      p->left = NIL;
      p->right = NIL;
      insert(p);
    }else{
      inorder(T);
      cout << endl;
      preorder(T);
      cout << endl;
    }
  }
}
