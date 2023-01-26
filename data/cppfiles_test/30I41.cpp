#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int par[N], ran[N];
struct DSU {
  DSU() {
    for (int i = 1; i <= N; ++i) par[i] = i;
  }
  int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
  bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    ran[a] += ran[a] == ran[b];
    if (ran[a] < ran[b]) swap(a, b);
    par[b] = a;
    return true;
  }
};
int a[N];
int n, q;
vector<int> primes;
int spf[N];
void sieve() {
  for (int i = 2; i <= N - 5; ++i) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] <= N - 5 && primes[j] <= spf[i];
         ++j) {
      spf[i * primes[j]] = primes[j];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();
  cin >> n >> q;
  DSU ds;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    while (x > 1) {
      ds.unite(spf[a[i]], x);
      x /= spf[x];
    }
  }
  set<pair<int, int>> pary;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    vector<int> v;
    while (x > 1) {
      v.push_back(spf[x]);
      x /= spf[x];
    }
    x = a[i] + 1;
    while (x > 1) {
      v.push_back(spf[x]);
      x /= spf[x];
    }
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto j : v) {
      for (auto k : v) {
        pary.insert({min(j, k), max(j, k)});
      }
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x = a[x], y = a[y];
    if (ds.find(x) == ds.find(y))
      cout << 0 << endl;
    else {
      x = ds.find(x);
      y = ds.find(y);
      if (x > y) swap(x, y);
      if (pary.count({x, y}))
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
