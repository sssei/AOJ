#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
double theta = M_PI / 3.0;

struct Point{
  double x,y;
};

void koch(int d, Point p1, Point p2){
  if(d == 0) return;
  
  Point s,t,u;
  s.x = (2.0 * p1.x + p2.x)/3.0;
  s.y = (2.0 * p1.y + p2.y)/3.0;
  t.x = (p1.x + 2.0 * p2.x)/3.0;
  t.y = (p1.y + 2.0 * p2.y)/3.0;
  u.x = (t.x - s.x) * cos(theta) - (t.y - s.y) * sin(theta) + s.x;
  u.y = (t.x - s.x) * sin(theta) + (t.y - s.y) * cos(theta) + s.y;
  koch(d - 1, p1, s);
  printf("%.8f %.8f\n", s.x, s.y);
  koch(d - 1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);
  koch(d - 1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  koch(d - 1, t, p2);
}

int main(){
  int n;
  scanf("%d",&n);
  Point a,b;
  a.x = 0.0;
  a.y = 0.0;
  b.x = 100.0;
  b.y = 0.0;

  printf("%.8f %.8f\n", a.x, a.y);
  koch(n, a, b);
  printf("%.8f %.8f\n", b.x, b.y);
}
