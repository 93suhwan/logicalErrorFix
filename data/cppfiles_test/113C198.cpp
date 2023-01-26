#include <bits/stdc++.h>
using namespace std;
const int N = 100;
void solve() {
  long long x1, x2, p1, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  if (p1 == p2) {
    if (x1 == x2) {
      printf("=\n");
    } else if (x1 > x2)
      printf(">\n");
    else
      printf("<\n");
  } else if (p1 > p2) {
    if (x1 >= x2)
      printf(">\n");
    else {
      int tt = p1 - p2;
      while (tt > 0 && x1 < x2) {
        x1 *= 10;
        tt--;
      }
      if (x1 == x2) {
        if (tt == 0)
          printf("=\n");
        else
          printf(">\n");
      } else if (x1 > x2)
        printf(">\n");
      else
        printf("<\n");
    }
  } else {
    if (x2 >= x1)
      printf("<\n");
    else {
      int tt = p2 - p1;
      while (tt > 0 && x2 < x1) {
        x2 *= 10;
        tt--;
      }
      if (x1 == x2) {
        if (tt == 0)
          printf("=\n");
        else
          printf("<\n");
      } else if (x1 < x2)
        printf("<\n");
      else
        printf(">\n");
    }
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
