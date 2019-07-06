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

void deleteNode(Node *T, bool flag){
  if(T->right == NIL && T->left == NIL){
    if(flag){
      T->parent->right = NIL;
    }else{
      T->parent->left = NIL;
    }
  }else if(T->right != NIL && T->left != NIL){
      T->key = T->right->key;
      deleteNode(T->right, true);
  }else{
    if(T->right != NIL){
      if(flag) T->parent->right = T->right;
      else T->parent->left = T->right;
    }else{
      if(flag) T->parent->right = T->left;
      else T->parent->left = T->left;
    }
  }
}

void search(int key, Node *T, bool flag){
  if(T->key == key) deleteNode(T, flag);
  else if(T->key > key) search(key, T->left, false);
  else search(key, T->right, true);
}

bool find(int key, Node* T){
  if(T == NIL) return false;
  if(T->key == key) return true;
  if(T->key < key) find(key, T->right);
  else find(key, T->left);
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
    }else{
      int key; cin >> key;
      Node root = {0, NIL, T, NIL};
      search(key, root.left, true);
    }
  }
}
