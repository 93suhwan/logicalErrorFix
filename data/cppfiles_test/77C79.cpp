#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const long double eps = 1e-6;
const long long int mod = 1e9 + 7;
const long long int mod2 = 998244353;
const long long int inf = 2e18;
const long long int inf2 = (1LL << 60);
const long long int maxn = 2e5 + 10;
void _print(long long int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(float t) { cerr << t; }
void google(long long int t) { cout << "Case #" << t << ": "; }
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
long long int power(long long int a, long long int y, long long int m) {
  long long int res = 1;
  a = a % m;
  while (y > 0) {
    if (y & 1) res = (res * a) % m;
    y = y >> 1LL;
    a = (a * a) % m;
  }
  return res;
}
long long int inverse(long long int n, long long int m) {
  return power(n, m - 2, m);
}
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long int mod_div(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, inverse(b, m), m));
}
void IOS() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(20);
  cout.setf(ios::fixed);
  freopen("Error.txt", "w", stderr);
}
vector<pair<long long int, long long int> > adj[1005][1005];
bool vis[1005][1005];
void addEdges(long long int x, long long int y, long long int xx,
              long long int yy) {
  adj[x][y].push_back({xx, yy});
  adj[xx][yy].push_back({x, y});
}
long long int val;
void dfs(long long int x, long long int y) {
  val++;
  vis[x][y] = true;
  for (auto &node : adj[x][y])
    if (!vis[node.first][node.second]) dfs(node.first, node.second);
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int arr[n][m];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      vis[i][j] = false;
      adj[i][j].clear();
      cin >> arr[i][j];
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (!(arr[i][j] & 1))
        if (j > 0) addEdges(i, j, i, j - 1);
      if (!(arr[i][j] & 2))
        if (i < n - 1) addEdges(i, j, i + 1, j);
      if (!(arr[i][j] & 4))
        if (j < m - 1) addEdges(i, j, i, j + 1);
      if (!(arr[i][j] & 8))
        if (i > 0) addEdges(i, j, i - 1, j);
    }
  }
  vector<long long int> ans;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        val = 0;
        dfs(i, j);
        ans.push_back(val);
      }
    }
  }
  sort((ans).rbegin(), (ans).rend());
  for (auto &i : ans) cout << i << " ";
  cout << "\n";
}
int32_t main() {
  IOS();
  long long int ttc = 1;
  while (ttc--) {
    auto start_time = chrono::high_resolution_clock::now();
    solve();
    cerr << "Executed in "
         << chrono::duration_cast<chrono::milliseconds>(
                chrono::high_resolution_clock::now() - start_time)
                .count()
         << "ms."
         << "\n";
  }
  return 0;
}
