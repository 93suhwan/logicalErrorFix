#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long int mod = 998244353;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int binpow(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int p = binpow(x, y / 2, m) % m;
  p = (p * p) % m;
  if (y % 2)
    return (x * p) % m;
  else
    return p;
}
long long int modi(long long int a, long long int m) {
  return binpow(a, m - 2, m);
}
long long int query(long long int tree[], long long int l, long long int r) {
  long long int ans = 0;
  while (l < r) {
    if (l % 2) {
      ans += tree[l];
      l++;
    }
    if (r % 2) {
      r--;
      ans += tree[r];
    }
    l /= 2;
    r /= 2;
  }
  return ans;
}
long long int find_set(long long int v, long long int parent[]) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v], parent);
}
void union_sets(long long int a, long long int b, long long int parent[]) {
  a = find_set(a, parent);
  b = find_set(b, parent);
  if (a != b) parent[b] = a;
}
long long int lca(long long int a, long long int b,
                  vector<vector<long long int>> &par, long long int depth[]) {
  if (depth[a] < depth[b]) swap(a, b);
  long long int diff = depth[a] - depth[b], ct = 0;
  while (diff) {
    if (diff % 2) {
      a = par[ct][a];
    }
    ct++;
    diff /= 2;
  }
  if (a == b) return a;
  for (long long int i = 19; i >= 0; i--) {
    if (par[i][a] != par[i][b]) {
      a = par[i][a];
      b = par[i][b];
    }
  }
  return par[0][a];
}
bool cmp1(const pair<long long int, long long int> &a,
          const pair<long long int, long long int> &b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
bool cmp2(const pair<long long int, long long int> &a,
          const pair<long long int, long long int> &b) {
  if (a.second != b.second) return a.second < b.second;
  return a.first < b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, tt = 1, tc;
  cin >> tt;
  for (tc = 1; tc <= tt; tc++) {
    long long int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<long long int> a(n), b(m);
    vector<pair<long long int, long long int>> p(k);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < m; i++) {
      cin >> b[i];
    }
    for (i = 0; i < k; i++) {
      cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), cmp1);
    long long int ct = 0, posy, posx, prevy = -1, prevx = -1, curr = 0;
    map<long long int, long long int> mm;
    for (i = 0; i < k; i++) {
      while (a[curr] < p[i].first) {
        curr++;
        ct = -1;
      }
      if (ct == -1) {
        ct = 0;
        mm.clear();
      }
      posy = (lower_bound(b.begin(), b.end(), p[i].second) - b.begin());
      posx = (lower_bound(a.begin(), a.end(), p[i].first) - a.begin());
      if (a[posx] == p[i].first) {
        ct = 0;
        mm.clear();
      } else {
        ans += (ct - mm[posy]);
        ct++;
        mm[posy]++;
      }
    }
    ct = 0;
    sort(p.begin(), p.end(), cmp2);
    curr = 0;
    mm.clear();
    for (i = 0; i < k; i++) {
      while (b[curr] < p[i].second) {
        curr++;
        ct = -1;
      }
      if (ct == -1) {
        ct = 0;
        mm.clear();
      }
      posy = (lower_bound(b.begin(), b.end(), p[i].second) - b.begin());
      posx = (lower_bound(a.begin(), a.end(), p[i].first) - a.begin());
      if (b[posy] == p[i].second) {
        ct = 0;
        mm.clear();
      } else {
        ans += (ct - mm[posx]);
        ct++;
        mm[posx]++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
