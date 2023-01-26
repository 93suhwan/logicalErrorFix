#include <bits/stdc++.h>
using namespace std;
[[maybe_unused]] constexpr int INF = (numeric_limits<int>::max()) / 2;
[[maybe_unused]] constexpr long long INFLL =
    (numeric_limits<long long>::max()) / 2;
[[maybe_unused]] constexpr __int128 INF128 = numeric_limits<__int128>::max();
template <class T>
istream &operator>>(istream &is, vector<T> &a) {
  for (auto &i : a) is >> i;
  return is;
}
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
int getrand(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }
long double getrand(long double l, long double r) {
  return uniform_real_distribution<long double>(l, r)(gen);
}
vector<vector<int>> w;
vector<int> gg;
long long check(vector<pair<int, int>> t) {
  long long ans = 0;
  for (auto [i, j] : t) ans += w[i][j];
  return ans;
}
struct dsu {
  vector<int> p, s;
  dsu(){};
  dsu(int n) {
    p.resize(n);
    s.resize(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  int get(int v) {
    if (p[v] == v) return v;
    return p[v] = get(p[v]);
  }
  void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (s[a] < s[b]) swap(a, b);
    s[a] += s[b];
    p[b] = a;
  }
};
int n;
void get(vector<pair<int, int>> &t, vector<int> &d) {
  int i = getrand(0, n - 2);
  int govno = 1;
  while (govno++ < 228) {
    if (govno % 20 == 0) i = getrand(0, n - 2);
    auto dd = d;
    dsu tmp(n);
    for (int j = 0; j < n - 1; ++j) {
      if (j != i) tmp.unite(t[j].first, t[j].second);
    }
    int v = getrand(0, n - 1), u = getrand(0, n - 1);
    while (tmp.get(u) == tmp.get(v)) u = getrand(0, n - 1);
    --dd[t[i].first];
    --dd[t[i].second];
    ++dd[v];
    ++dd[u];
    bool check = true;
    for (int ggi = 0; ggi < gg.size(); ++ggi) {
      if (dd[ggi] > gg[ggi]) check = false;
    }
    if (check) {
      t.erase(t.begin() + i);
      t.push_back({u, v});
      d = dd;
      return;
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int k;
  cin >> n >> k;
  gg.resize(k);
  cin >> gg;
  w.resize(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cin >> w[i][j];
      w[j][i] = w[i][j];
    }
  }
  int timera = 0;
  long long ans = INF;
  while (timera++ < 25) {
    long double temp = 1;
    int timerb = 0;
    vector<pair<int, int>> t;
    vector<int> d(n, 0);
    int leaf1 = 0, leaf2 = n - 1;
    if (count(gg.begin(), gg.end(), 1) >= 1)
      leaf1 = find(gg.begin(), gg.end(), 1) - gg.begin();
    if (count(gg.begin(), gg.end(), 1) == 2) {
      for (int i = k - 1; i >= 0; --i)
        if (gg[i] == 1) {
          leaf2 = i;
          break;
        }
    }
    for (int i = 0; i + 1 < n; ++i) t.push_back({i, i + 1});
    int govno1 = 0, govno2 = n - 1;
    for (int i = 0; i + 1 < n; ++i) {
      if (t[i].first == govno1) t[i].first = leaf1;
      if (t[i].second == govno2) t[i].second = leaf2;
      if (t[i].first == leaf1) t[i].first = govno1;
      if (t[i].second == leaf2) t[i].second = govno2;
    }
    for (auto [i, j] : t) {
      ++d[i];
      ++d[j];
    }
    ans = min(ans, check(t));
    while (timerb++ < 4000) {
      temp *= 0.997;
      auto oldt = t;
      auto oldd = d;
      get(t, d);
      long long res = check(oldt) - check(t);
      if (exp((long double)res / temp) >
          getrand((long double)0.0, (long double)1.0)) {
        ans = min(ans, check(t));
        continue;
      }
      t = oldt;
      d = oldd;
    }
  }
  cout << ans;
  cout << "\n";
}
