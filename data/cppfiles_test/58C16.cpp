#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int MX = 2e5;
struct {
  int st[MX + 5];
  void upd(int t, int v) {
    while (t <= MX) st[t] += v, t += t & -t;
  }
  int get(int t) {
    int r = 0;
    while (t) r += st[t], t -= t & -t;
    return r;
  }
} fw;
ll F[MX * 2], F_[MX * 2];
void sol() {
  int n, m;
  cin >> n >> m;
  vector<int> x, y;
  for (int i = 0, u, v; i < m; i++)
    cin >> u >> v, x.emplace_back(u), y.emplace_back(v);
  vector<pair<int, int>> p;
  int k = m;
  for (int i = m - 1; i >= 0; i--) {
    int s = y[i], e = n;
    while (s < e) {
      int m = (s + e) / 2;
      if (m - fw.get(m) >= y[i])
        e = m;
      else
        s = m + 1;
    }
    p.emplace_back(s, x[i]);
    fw.upd(s, 1);
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < m - 1; i++)
    if (p[i].first + 1 == p[i + 1].first && p[i].second < p[i + 1].second) k--;
  for (auto &i : p) fw.upd(i.first, -1);
  cout << F[2 * n - k - 1] * F_[n] % MOD * F_[n - k - 1] % MOD << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  F[0] = 1;
  for (int i = 1; i < 2 * MX; i++) F[i] = F[i - 1] * i % MOD;
  ll &x = F_[2 * MX - 1];
  x = 1;
  for (int i = 30; i >= 0; i--) {
    x = x * x % MOD;
    if ((1 << i) & (MOD - 2)) x = x * F[2 * MX - 1] % MOD;
  }
  for (int i = 2 * MX - 2; i >= 0; i--) F_[i] = F_[i + 1] * (i + 1) % MOD;
  int t;
  cin >> t;
  while (t--) sol();
  return 0;
}
