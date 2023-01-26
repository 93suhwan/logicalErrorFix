#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int MX = 2e5;
ll F[MX * 2], F_[MX * 2];
void sol() {
  int n, m;
  cin >> n >> m;
  vector<int> x, y;
  for (int i = 0, u, v; i < m; i++)
    cin >> u >> v, x.emplace_back(u), y.emplace_back(v);
  vector<pair<int, int>> p;
  set<pair<int, int>> st;
  for (int i = m - 1; i >= 0; i--) {
    auto j = st.upper_bound(pair<int, int>(y[i], y[i]));
    int l;
    if (j == st.begin() || prev(j)->second < y[i])
      l = y[i];
    else
      l = prev(j)->second + 1;
    p.emplace_back(l, x[i]);
    pair<int, int> ins(l, l);
    j = st.upper_bound(ins);
    if (j != st.end() && j->first == l + 1) {
      ins.second = j->second;
      st.erase(j);
    }
    j = st.upper_bound(ins);
    if (j != st.begin() && prev(j)->second + 1 == l) {
      --j;
      ins.first = j->first;
      st.erase(j);
    }
    st.insert(ins);
  }
  int k = m;
  sort(p.begin(), p.end());
  for (int i = 0; i < m - 1; i++)
    if (p[i].first + 1 == p[i + 1].first && p[i].second < p[i + 1].second) k--;
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
