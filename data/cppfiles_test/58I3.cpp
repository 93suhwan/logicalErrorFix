#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int MX = 2e5;
ll F[MX * 2], F_[MX * 2];
struct {
  int p[MX + 5];
  int gp(int x) { return p[x] ? (p[x] = gp(p[x])) : x; }
  void un(int x, int y) {
    x = gp(x);
    y = gp(y);
    if (x != y) p[x] = y;
  }
} uf;
void sol() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m);
  for (int i = 0; i < m; i++) cin >> x[i] >> y[i];
  vector<pair<int, int>> p;
  for (int i = m - 1; i >= 0; i--) {
    int z = uf.gp(y[i]);
    p.emplace_back(z, x[i]);
    uf.un(z, z + 1);
  }
  int k = m;
  sort(p.begin(), p.end());
  for (int i = 0; i < m - 1; i++)
    if (p[i].first + 1 == p[i + 1].first && p[i].second < p[i + 1].second) k--;
  for (auto &i : p) uf.p[i.first] = 0;
  cout << (F[2 * n - k - 1] * F_[n] % MOD * F_[n - k - 1] % MOD) << '\n';
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
  for (int i = 0; i < 2 * MX; i++) assert(F[i] * F_[i] % MOD == 1);
  int t;
  cin >> t;
  while (t--) sol();
  return 0;
}
