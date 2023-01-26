#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 200005;
long long w, h;
long long n, m;
long long givenw, givenh;
long long rightup(long long x1, long long x2, long long y1, long long y2) {
  long long tox = n - w;
  long long toy = m - h;
  long long d = tox - givenw;
  long long e = toy - givenh;
  if (x2 <= tox || y2 <= toy) {
    return 0;
  }
  long long ans = INT_MAX;
  if (e >= 0) {
    ans = min(ans, abs(y2 - toy));
  }
  if (d >= 0) {
    ans = min(ans, abs(x2 - tox));
  }
  if (d >= 0 && e >= 0) {
    ans = min(ans, abs(tox - x2) + abs(toy - y2));
  }
  return ans;
}
long long rightdown(long long x1, long long x2, long long y1, long long y2) {
  long long tox = n - w;
  long long toy = h;
  long long d = tox - givenw;
  long long e = toy + givenh;
  if (x2 <= tox || y1 >= toy) {
    return 0;
  }
  long long ans = INT_MAX;
  if (e <= m) {
    ans = min(ans, abs(y1 - toy));
  }
  if (d >= 0) {
    ans = min(ans, abs(x2 - tox));
  }
  if (d >= 0 && e <= m) {
    ans = min(ans, abs(tox - x2) + abs(toy - y1));
  }
  return ans;
}
long long leftup(long long x1, long long x2, long long y1, long long y2) {
  long long tox = w;
  long long toy = m - h;
  long long d = tox + givenw;
  long long e = toy - givenh;
  if (x1 >= tox || y2 <= toy) {
    return 0;
  }
  long long ans = INT_MAX;
  if (e >= 0) {
    ans = min(ans, abs(y2 - toy));
  }
  if (d <= n) {
    ans = min(ans, abs(x1 - tox));
  }
  if (d <= n && e >= 0) {
    ans = min(ans, abs(tox - x1) + abs(toy - y2));
  }
  return ans;
}
long long leftdown(long long x1, long long x2, long long y1, long long y2) {
  long long tox = w;
  long long toy = h;
  long long d = tox + givenw;
  long long e = toy + givenh;
  if (x1 >= tox || y1 >= toy) {
    return 0;
  }
  long long ans = INT_MAX;
  if (e <= m) {
    ans = min(ans, abs(y1 - toy));
  }
  if (d <= n) {
    ans = min(ans, abs(x1 - tox));
  }
  if (d <= n && e <= m) {
    ans = min(ans, abs(tox - x1) + abs(toy - y1));
  }
  return ans;
}
void solve() {
  cout << fixed << setprecision(6);
  cin >> n >> m;
  long long x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  givenw = abs(x2 - x1);
  givenh = abs(y2 - y1);
  cin >> w >> h;
  long long a = rightup(x1, x2, y1, y2);
  long long b = rightdown(x1, x2, y1, y2);
  long long c = leftup(x1, x2, y1, y2);
  long long d = leftdown(x1, x2, y1, y2);
  long long ans = min(a, b);
  ans = min(b, c);
  ans = min(c, d);
  if (ans == INT_MAX) {
    ans = -1;
    cout << ans << "\n";
    return;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
