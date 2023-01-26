#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const double EPS = 1e-8;
const double PI = acos(-1.0);
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
const int N = 1e6 + 5;
vector<vector<int>> adj(N);
vector<int> dp(N);
vector<int> arr(N);
vector<int> visited(N);
void dfs(int u) {
  visited[u] = 1;
  if (arr[u] == 0) dp[u] = 1;
  for (int v : adj[u]) {
    if (dp[u] != -1) {
      dp[v] = max(dp[u] + 1, dp[v]);
    }
    if (visited[v]) continue;
    dfs(v);
    if (dp[u] != -1) {
      dp[v] = max(dp[u] + 1, dp[v]);
    }
  }
}
void solve() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i <= n; ++i) {
    adj[i].clear();
    dp[i] = -1;
    arr[i] = 0;
    visited[i] = 0;
  }
  bool ones = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i]) ones = 1;
  }
  for (int i = 0; i < n; ++i) {
    int pos = (i - d + n) % n;
    if (arr[i] == 0) continue;
    adj[pos].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    if (visited[i] || arr[i] == 1) continue;
    dfs(i);
  }
  int ans = -1;
  bool bad = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 1 && dp[i] == -1) {
      bad = 1;
    }
    if (dp[i] != -1) ans = max(ans, dp[i] - 1);
    ;
  }
  if (bad) {
    cout << "-1\n";
    return;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
