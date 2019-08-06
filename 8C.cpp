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

Node* getMinimun(Node *x){
  while(x->left != NIL){
      x = x->left;
  }
  return x;
}

Node* getSuccessor(Node *x){
  if(x->right != NIL){
    return getMinimun(x->right);
  }
  Node *y = x->parent;
  while(y != NIL && y->right == x){
    x = y;
    y = y->parent;
  }
  return y;
}
 
void deleteNode(Node *T, Node* z){
  Node *y;
  if(z->left == NIL || z->right == NIL){
    y = z;
  }else{
    y = getSuccessor(z);
  }

  Node *x;
  if(y->left != NIL){
    x = y->left;
  }else{
    x = y->right;
  }

  if(y->parent == NIL){
    T = x;
  }else if(y->parent->right == y){
    y->parent->right = x;
  }else{
    y->parent->left = x;
  }

  if(y != z){
    z->key = y->key;
  }
}


Node *find(Node *u, int k){
  while(u != NIL && k != u->key){
    if(k < u->key) u = u->left;
    else u = u->right;
  }
  return u;
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
    }else if(order[0] == 'p'){
      inorder(T);
      cout << endl;
      preorder(T);
      cout << endl;
    }else if(order[0] == 'f'){
      int key; cin >> key;
      if(find(key, T)){
	cout << "yes" << endl;
      }else{
	cout << "no" << endl;
      }
    }else if(order[0] == 'd'){
      int key; cin >> key;
      Node *p = new Node;
      p->key = key;
      p->parent = NIL;
      p->left = NIL;
      p->right = NIL;
      deleteNode(T, p);
    }
  }
}
