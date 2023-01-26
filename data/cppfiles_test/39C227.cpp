#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long int maxn = 2e5 + 16, md = 1e9 + 7, inf = 2e16;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int tav(long long int n, long long int k) {
  long long int res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= n;
      res %= md;
    }
    n *= n;
    n %= md;
    k >>= 1;
  }
  return res;
}
void solve() {
  long long int H, W, h, w, x1, x2, y1, y2;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  if (w + x2 - x1 > W && h + y2 - y1 > H) {
    cout << "-1\n";
    return;
  }
  long long int x, y;
  x = w;
  y = h;
  long long int ans = inf;
  if (w + x2 - x1 <= W) {
    ans = min(ans, x - x1);
    x = W - w;
    ans = min(ans, x2 - x);
  }
  if (h + y2 - y1 <= H) {
    ans = min(ans, y - y1);
    y = H - h;
    ans = min(ans, y2 - y);
  }
  cout << (ans < 0 ? 0 : ans) << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
