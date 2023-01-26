#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
const int INF = 1e9;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void dfs(int i, vector<vector<int> > &adj, vector<int> &vis) {
  vis[i] = 1;
  for (auto &x : adj[i]) {
    if (!vis[x]) {
      dfs(x, adj, vis);
    }
  }
}
bool check(vector<int> &x, int m, vector<int> &a) {
  int n = x.size();
  vector<vector<int> > adj(n);
  map<int, int> make_pair;
  for (int i = 0; i < n; i++) {
    make_pair[a[i]] = i;
  };
  for (int i = 0; i < n; i++) {
    if (a[i] == x[i]) continue;
    int ori = make_pair[x[i]];
    adj[x[i] - 1].push_back(x[ori] - 1);
    adj[x[ori] - 1].push_back(x[i] - 1);
  };
  vector<int> vis(n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      ans++;
      dfs(i, adj, vis);
    }
  }
  return n - ans <= m;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> shift(n, 0);
  map<int, int> pos;
  for (int i = 0; i < n; i++) {
    int ori = a[i] - 1;
    shift[(i - ori + n) % n]++;
    pos[a[i]] = i;
  };
  vector<int> ans;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    if (shift[i] < n / 3) continue;
    for (int j = 1; j <= n; j++) {
      x[(j - 1 + i) % n] = j;
    };
    ;
    if (check(x, m, a)) ans.push_back(i);
  }
  cout << ans.size() << " ";
  for (auto &x : ans) cout << x << " ";
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
