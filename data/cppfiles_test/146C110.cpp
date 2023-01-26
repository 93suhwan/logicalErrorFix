#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int sq = 320;
int n, q, p[N], r[N], dp[N];
int f(int x) {
  int y = x;
  for (int i = 0; i < sq; i++) x = p[x];
  return dp[y] = x;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    r[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) f(i);
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      swap(r[p[x]], r[p[y]]);
      swap(p[x], p[y]);
      vector<int> v = {x, y};
      for (int au : v) {
        int here = au;
        int nxt = f(here);
        for (int i = 0; i < sq; i++) {
          dp[here] = nxt;
          here = r[here];
          nxt = r[nxt];
        }
      }
    } else {
      while (y >= sq) {
        y -= sq;
        x = dp[x];
      }
      while (y) {
        y--;
        x = p[x];
      }
      cout << x << '\n';
    }
  }
  return 0;
}
