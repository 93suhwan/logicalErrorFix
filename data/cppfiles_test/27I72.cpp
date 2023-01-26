#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, P = 1e9 + 7;
int T, n, m, K;
int pd(int x, int y) { puts(x < y ? "YES" : "NO"); }
int solve() {
  scanf("%d%d%d", &n, &m, &K);
  K--;
  if (m < n - 1)
    puts("NO");
  else if (n == 1)
    pd(0, K);
  else if (m >= n * (n - 1) / 2)
    pd(1, K);
  else
    pd(2, K);
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
}
