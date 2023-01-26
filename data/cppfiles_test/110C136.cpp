#include <bits/stdc++.h>
using namespace std;
void _print(bool t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ", ";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(set<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[  ";
  for (auto i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T>
void _print(T v[], int n) {
  cerr << "[  ";
  for (int i = 0; i < n; i++) {
    _print(v[i]);
    cerr << "  ";
  }
  cerr << "]\n";
}
const int MAX = 2e5 + 10;
vector<int> adj[MAX];
int ans[MAX], vis[MAX], rec[MAX];
bool cycle = false;
void solve(int u) {
  vis[u] = true;
  rec[u] = true;
  int mx1 = 0, mx2 = 0;
  for (int v : adj[u]) {
    if (!vis[v])
      solve(v);
    else if (rec[v])
      cycle = true;
    if (v > u)
      mx2 = max(mx2, ans[v]);
    else
      mx1 = max(mx1, ans[v]);
  }
  rec[u] = false;
  if (adj[u].size() == 0) {
    ans[u] = 1;
    return;
  }
  if (mx2 > 0) {
    ans[u] = max(mx1, mx2 + 1);
  } else {
    ans[u] = mx1;
  }
}
void run() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
    ans[i] = -1;
    cycle = false;
    vis[i] = false;
    rec[i] = false;
  }
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--;
      adj[i].push_back(v);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) solve(i);
  }
  if (cycle)
    cout << -1 << '\n';
  else
    cout << *max_element(ans, ans + n) << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie();
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    run();
  }
}
