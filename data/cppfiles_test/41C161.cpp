#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  long long int abc[n + 1], acb[n + 1], bac[n + 1], bca[n + 1], cab[n + 1],
      cba[n + 1];
  abc[0] = 0, acb[0] = 0, bac[0] = 0, bca[0] = 0, cab[0] = 0, cba[0] = 0;
  string a = "abc", b = "acb", c = "bac", d = "bca", e = "cab", f = "cba";
  if (s[0] == 'a')
    abc[1] = 0;
  else
    abc[1] = 1;
  if (s[0] == 'a')
    acb[1] = 0;
  else
    acb[1] = 1;
  if (s[0] == 'b')
    bac[1] = 0;
  else
    bac[1] = 1;
  if (s[0] == 'b')
    bca[1] = 0;
  else
    bca[1] = 1;
  if (s[0] == 'c')
    cab[1] = 0;
  else
    cab[1] = 1;
  if (s[0] == 'c')
    cba[1] = 0;
  else
    cba[1] = 1;
  for (long long int i = 1; i < n; i++) {
    if (s[i] == a[i % 3])
      abc[i + 1] = abc[i];
    else
      abc[i + 1] = abc[i] + 1;
    if (s[i] == b[i % 3])
      acb[i + 1] = acb[i];
    else
      acb[i + 1] = acb[i] + 1;
    if (s[i] == c[i % 3])
      bac[i + 1] = bac[i];
    else
      bac[i + 1] = bac[i] + 1;
    if (s[i] == d[i % 3])
      bca[i + 1] = bca[i];
    else
      bca[i + 1] = bca[i] + 1;
    if (s[i] == e[i % 3])
      cab[i + 1] = cab[i];
    else
      cab[i + 1] = cab[i] + 1;
    if (s[i] == f[i % 3])
      cba[i + 1] = cba[i];
    else
      cba[i + 1] = cba[i] + 1;
  }
  for (long long int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    x--;
    long long int ans = INT_MAX;
    ans = min((abc[y] - abc[x]), min((acb[y] - acb[x]), bac[y] - bac[x]));
    ans = min(ans,
              min((bca[y] - bca[x]), min((cab[y] - cab[x]), cba[y] - cba[x])));
    cout << ans << '\n';
  }
}
int32_t main() {
  long long int t = 1;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (t--) {
    solve();
  }
}
