#include <bits/stdc++.h>
using namespace std;
void SA();
void SB();
void SC();
void SD();
int main() {
  int T;
  scanf("%d", &T);
  ;
  for (int I = 1; I <= T; I++) {
    SC();
  }
}
void SC() {
  int n;
  scanf("%d", &n);
  ;
  int tem = ceil(double(sqrt(n)));
  int prev = tem - 1;
  prev = prev * prev;
  int x, y;
  if (prev + tem == n) {
    x = tem;
    y = tem;
  } else if (prev + tem > n) {
    x = n - prev;
    y = tem;
  } else {
    y = tem * tem - n + 1;
    x = tem;
  }
  cout << x << " " << y << endl;
}
