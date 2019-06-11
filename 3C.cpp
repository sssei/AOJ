#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

struct Node{
  int key;
  Node *next,*prev;
};

Node *nil;

void init(){
  nil = new Node;
  nil->next = nil;
  nil->prev = nil;
}

void insert(int key){
  Node *x = new Node;
  x->next = nil->next;
  nil->next->prev = x->next;
  nil->prev = x;
  x->prev = nil;
}

Node* listSearch(int key){
  Node *cur = nil->next;
  while(cur != nil && cur->key != key){
    cur = cur->next;
  }
  return cur;
}

void deleteNode(Node* t){
  if(t == nil) return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  delete t;
}

void deleteFirst(){
  deleteNode(nil->next);
}

void deleteLast(){
  deleteNode(nil->prev);
}

void deletekey(int key){
  deleteNode(listSearch(key));
}

void printNode(){
  Node *cur = nil->next;
  printf("%d",cur->key);
  cur = cur->next;
  while(cur != nil){
    printf(" %d",cur->key);
    cur = cur->next;
  }
  printf("\n");
}

int main(){
  int n;
  init();
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    char s[10];
    int c;
    scanf("%s", s);
    if(strcmp(s,"insert") == 0){
      scanf("%d", &c);
      insert(c);
    }else if(strcmp(s,"delete") == 0){
      scanf("%d", &c);
      deletekey(c);
    }else if(strcmp(s,"deleteFirst") == 0){
      deleteFirst();
    }else{
      deleteLast();
    }
  }
  printNode();  
}
