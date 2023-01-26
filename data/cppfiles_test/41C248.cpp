#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<long long>;
const ll mod = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  s = ' ' + s;
  int a[n + 1], b[n + 1], c[n + 1], d[n + 1], e[n + 1], f[n + 1];
  a[0] = b[0] = c[0] = d[0] = e[0] = f[0] = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1];
    b[i] = b[i - 1];
    c[i] = c[i - 1];
    d[i] = d[i - 1];
    e[i] = e[i - 1];
    f[i] = f[i - 1];
    if (i % 3 == 1) {
      if (s[i] == 'a') {
        c[i]++;
        d[i]++;
        e[i]++;
        f[i]++;
      } else if (s[i] == 'b') {
        a[i]++;
        b[i]++;
        e[i]++;
        f[i]++;
      } else {
        a[i]++;
        b[i]++;
        c[i]++;
        d[i]++;
      }
    } else if (i % 3 == 2) {
      if (s[i] == 'a') {
        a[i]++;
        b[i]++;
        d[i]++;
        f[i]++;
      } else if (s[i] == 'b') {
        b[i]++;
        c[i]++;
        d[i]++;
        e[i]++;
      } else {
        a[i]++;
        c[i]++;
        e[i]++;
        f[i]++;
      }
    } else {
      if (s[i] == 'a') {
        a[i]++;
        b[i]++;
        c[i]++;
        e[i]++;
      } else if (s[i] == 'b') {
        a[i]++;
        c[i]++;
        d[i]++;
        f[i]++;
      } else {
        b[i]++;
        d[i]++;
        e[i]++;
        f[i]++;
      }
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    int ans = 1e9;
    ans = min(ans, a[r] - a[l - 1]);
    ans = min(ans, b[r] - b[l - 1]);
    ans = min(ans, c[r] - c[l - 1]);
    ans = min(ans, d[r] - d[l - 1]);
    ans = min(ans, e[r] - e[l - 1]);
    ans = min(ans, f[r] - f[l - 1]);
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(15) << fixed;
  int t = 1;
  while (t--) solve();
  return 0;
}
