#include <bits/stdc++.h>
using namespace std;
const long long I1 = 1e9;
const long long I2 = 1e18;
const int32_t M1 = 1e9 + 7;
const int32_t M2 = 998244353;
template <typename T, typename T1>
T maxn(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T minn(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<long long int> par(200005), ord(200005), mn(200005);
long long int parent(long long int i) {
  if (par[i] == i)
    return i;
  else
    return par[i] = parent(par[i]);
}
bool pfind(long long int x, long long int y) { return parent(x) == parent(y); }
void merge(long long int x, long long int y) {
  x = parent(x);
  y = parent(y);
  if (ord[x] > ord[y]) {
    par[y] = x;
    ord[x] += ord[y];
    minn(mn[x], mn[y]);
  } else {
    par[x] = y;
    ord[y] += ord[x];
    minn(mn[y], mn[x]);
  }
}
void clear_dsu(int n) {
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    ord[i] = 1;
    mn[i] = I2;
  }
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  clear_dsu(n + 1);
  map<long long int, long long int> timer;
  map<long long int, vector<long long int> > x, y;
  map<pair<long long int, long long int>, int> ind;
  for (int i = 0; i < n; i++) {
    long long int l, r, t;
    cin >> l >> r >> t;
    timer[i + 1] = t;
    x[l].push_back(r);
    y[r].push_back(l);
    ind[{l, r}] = i + 1;
    mn[i + 1] = t;
  }
  for (auto u : x) {
    vector<long long int> v = u.second;
    for (int i = 1; i < (long long int)v.size(); i++) {
      if (v[i] - v[i - 1] <= k) {
        merge(ind[{u.first, v[i - 1]}], ind[{u.first, v[i]}]);
      }
    }
  }
  for (auto u : y) {
    vector<long long int> v = u.second;
    for (int i = 1; i < (long long int)v.size(); i++) {
      if (v[i] - v[i - 1] <= k) {
        merge(ind[{v[i - 1], u.first}], ind[{v[i], u.first}]);
      }
    }
  }
  map<long long int, long long int> val;
  long long int total = 0;
  for (int i = 1; i <= n; i++) {
    if (parent(i) == i) {
      val[mn[i]]++;
      total++;
    }
  }
  long long int cnt = 0;
  for (int i = 0; i < total; i++) {
    cnt += val[i];
    if (i + 1 + cnt >= total) {
      cout << i << '\n';
      return;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testcase = 1;
  cin >> testcase;
  while (testcase--) solve();
  return 0;
}
