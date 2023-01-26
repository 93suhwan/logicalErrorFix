#include <bits/stdc++.h>
void solve() {
  int P;
  scanf("%d", &P);
  int a, b;
  a = P - 1;
  b = (P - 1) / 2;
  printf("%d %d\n", a, b);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
