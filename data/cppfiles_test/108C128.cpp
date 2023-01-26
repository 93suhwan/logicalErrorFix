#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long double pi = 3.14159265358979323846;
long long n, m, k, q, l, r, x, y, z;
const long long template_array_size = 1e6 + 5;
long long a[template_array_size];
long long b[template_array_size];
long long c[template_array_size];
string second, t;
long long ans = 0;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
void dfs(int n, vector<int> adj[], vector<int> &vis) {
  if (vis[n]) return;
  vis[n] = 1;
  for (auto i : adj[n]) {
    if (!vis[i]) dfs(i, adj, vis);
  }
}
void solve() {
  cin >> n;
  vector<pair<int, int> > a(n), b(n);
  pair<int, int> mx = {INT_MIN, INT_MIN};
  for (long long i = 0; i < (n); ++i) {
    int t;
    cin >> t;
    a.push_back({t, i});
    if (t > mx.first) {
      mx.first = t;
      mx.second = i;
    }
  }
  for (long long i = 0; i < (n); ++i) {
    int t;
    cin >> t;
    b.push_back({t, i});
    if (t > mx.first) {
      mx.first = t;
      mx.second = i;
    }
  }
  vector<int> adj[n];
  vector<int> vis(n, 0);
  sort(a.begin(), a.end(), cmp);
  for (int i = 1; i < n; ++i) {
    adj[a[i].second].push_back(a[i - 1].second);
  }
  sort(b.begin(), b.end(), cmp);
  for (int i = 1; i < n; ++i) {
    adj[b[i].second].push_back(b[i - 1].second);
  }
  dfs(mx.second, adj, vis);
  for (auto i : vis) cout << i;
  cout << '\n';
}
int main() {
  { ios_base::sync_with_stdio(false); }
  {
    cin.tie(NULL);
    cout.tie(NULL);
  }
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve();
}
