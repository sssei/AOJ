#include <cstdio>
#include <cstring>
#define LEN 1046527

char H[LEN][14];

int h1(int key){ return key%LEN;}

int h2(int key){ return 1 + (key%(LEN - 1));}

int h(int key, int i){
  return (h1(key) + i * h2(key)) % LEN;
}

int getChar(char ch){
  if(ch == 'A') return 1;
  else if(ch == 'C') return 2;
  else if(ch == 'T') return 3;
  else return 4;
}

long long getKey(const char* c){
  int len = strlen(c);
  long long key = 0, p = 1;
  for(int i = 0; i < len; i++){
    key += getChar(c[i]) * p;
    p *= 5;
  }
  return key;
}

int insert(char str[]){
  int i = 0;
  long long key = getKey(str);
  while(1){
    int j = h(key,i);
    if(strcmp(H[j],str) == 0){
      return 1;
    }else if(strlen(H[j]) == 0){
      strcpy(H[j],str);
      return 0;
    }
    i++;
  }
}

int search(char str[]){
  int i = 0;
  long long key = getKey(str);
  while(1){
    int j = h(key,i);
    if(strcmp(H[j],str) == 0) return 1;
    else if(strlen(H[j]) == 0) return 0;
    i++;
  }
}

int main(){
  int n; scanf("%d",&n);
  for(int i = 0; i < LEN; i++) H[i][0] = '\0';
  for(int i = 0; i < n; i++){
    char ord[9];
    char str[14];
    scanf("%s %s",ord,str);
    if(ord[0] == 'i'){
      insert(str);
    }else{
      if(search(str)){
	printf("yes\n");
      }else{
	printf("no\n");
      }
    }
  } 
}
