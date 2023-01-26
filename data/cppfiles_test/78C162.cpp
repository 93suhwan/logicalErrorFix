#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 1e6 + 7, P = 131;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
void solve() {
  int l, r;
  scanf("%d%d", &l, &r);
  int t = r / 2 + 1;
  int ans = 0;
  if (t >= l)
    ans = r - t;
  else
    ans = r - l;
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
