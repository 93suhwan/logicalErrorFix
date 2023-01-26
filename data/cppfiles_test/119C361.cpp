#include <bits/stdc++.h>
using namespace std;
void solve() {
  int i, j, k, a, b, c, n;
  scanf("%d", &n);
  a = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &b);
    a += b;
  }
  if (a % n == 0)
    printf("0\n");
  else
    printf("1\n");
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
