#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
const long long N = 2e5 + 10;
template <typename T>
bool ckmin(T& a, T b) {
  return b < a && (a = b, true);
}
template <typename T>
bool ckmax(T& a, T b) {
  return b > a && (a = b, true);
}
void testCase() {
  long long n, m;
  cin >> n >> m;
  vector<long long> p(n), inv_p(n);
  for (long long& i : p) cin >> i, i--;
  vector<long long> reach(n);
  long long S = sqrt(0.45 * n) + 0.5;
  for (long long i = 0; i < n; i++) {
    long long& x = reach[i] = i;
    inv_p[p[i]] = i;
    for (long long r = 0; r < S; r++) {
      x = p[x];
    }
  }
  for (long long i = 0; i < m; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x, y;
      cin >> x >> y;
      x--, y--;
      long long px = x, py = y;
      for (long long r = 0; r < S; r++) px = inv_p[px], py = inv_p[py];
      swap(p[x], p[y]);
      inv_p[p[x]] = x, inv_p[p[y]] = y;
      x = px, y = py;
      for (long long r = 0; r < S; r++) x = p[x], y = p[y];
      for (long long r = 0; r <= S; r++) {
        reach[px] = x, reach[py] = y;
        px = p[px], py = p[py];
        x = p[x], y = p[y];
      }
    } else {
      long long x, k;
      cin >> x >> k;
      x--;
      while (k >= S) {
        x = reach[x];
        k -= S;
      }
      while (k--) {
        x = p[x];
      }
      cout << x + 1 << '\n';
    }
  }
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long t_c = 1;
  while (t_c--) testCase();
}
