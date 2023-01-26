#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
long long res = 0;
string t[20];
long long w[20];
int ans[200000];
void get(long long x) {
  int s = 0;
  int k[n], f[n], p = 0;
  for (int i = 0; i < n; i++) k[i] = 1;
  while (x > 0) {
    if (x % 2 == 1) {
      k[p] = -1;
      s += w[p];
    }
    p++;
    x /= 2;
  }
  for (int i = 0; i < n; i++)
    if (k[i] == 1) s -= w[i];
  vector<pair<int, int> > a(m);
  for (int i = 0; i < m; i++) {
    a[i].first = 0;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (t[i][j] == '1') a[j].first += k[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < m; i++) s += a[i].first * (i + 1);
  if (s > res) {
    res = s;
    for (int i = 0; i < m; i++) ans[a[i].second] = i + 1;
    return;
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int x = 0; x < (1 << n); x++) get(x);
  for (int i = 0; i < m; i++) cout << ans[i] << ' ';
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  int q;
  cin >> q;
  while (q--) solve();
}
