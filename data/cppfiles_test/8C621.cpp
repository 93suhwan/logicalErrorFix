#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  int c1, c2;
  c1 = n / 3;
  c2 = (n - c1) / 2;
  int add = (c2 * 2) + c1;
  int less = n - add;
  int first = 0, seco = 0;
  first = c1 + less;
  printf("%d %d\n", first, c2);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
