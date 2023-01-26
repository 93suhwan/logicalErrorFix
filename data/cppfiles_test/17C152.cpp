#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n;
int tr[N], a[N], b[N];
int k;
void add(int x, int y) {
  while (x <= n) tr[x] += y, x += x & -x;
}
int ask(int x) {
  int res = 0;
  while (x) res += tr[x], x -= x & -x;
  return res;
}
void solve() {
  cin >> n;
  map<int, int> mp;
  memset(tr, 0, sizeof tr);
  k = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  for (int i = 0; i < n; i++)
    if (!mp.count(b[i])) mp[b[i]] = ++k;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0)
      add(mp[a[i]], 1);
    else {
      int h = ask(mp[a[i]] - 1), t = ask(n) - ask(mp[a[i]]);
      if (h <= t)
        ans += h;
      else
        ans += t;
      add(mp[a[i]], 1);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
