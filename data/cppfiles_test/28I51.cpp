#include <bits/stdc++.h>
using namespace std;
void work() {
  int a, b, c;
  int ans = 0;
  scanf("%d %d %d", &a, &b, &c);
  if (a == b && a == c) {
    printf("0\n");
    return;
  }
  if (c % 2 == 0) {
    c = 0;
  } else {
    c = 0;
    a--;
    b--;
  }
  if (b % 2 == 0) {
    b = 0;
  } else {
    if (a >= 2) {
      a -= 2;
      b = 0;
    } else {
      ans = 2 - a;
      a = 0;
    }
  }
  if (a % 2 == 0) {
    a = 0;
  } else {
    ans += 1;
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
}
