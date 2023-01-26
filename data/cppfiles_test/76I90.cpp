#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 2;
const int mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
T rand(T a, T b) {
  return uniform_int_distribution<T>(a, b)(rng);
}
template <class T>
T rand() {
  return uniform_int_distribution<T>()(rng);
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
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
vector<vector<int>> g;
int n, m;
bool check(vector<int> &arr) {
  int tot = 0;
  for (auto &x : arr) {
    for (auto &y : arr) {
      tot += g[x][y];
    }
  }
  return (tot == 10 || tot == 0);
}
bool recur(int str, vector<int> &arr) {
  if (arr.size() == 5) {
    return check(arr);
  }
  for (int i = str; i < n + 1; i++) {
    arr.push_back(i);
    if (recur(i + 1, arr)) return 1;
    arr.pop_back();
  }
  return false;
}
void solve() {
  cin >> n >> m;
  int maxi = 43;
  n = min(n, maxi);
  g.resize(n + 1, vector<int>(n + 1));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > n || b > n) continue;
    g[a][b]++;
    g[b][a]++;
  }
  vector<int> arr;
  if (recur(1, arr)) {
    for (auto &x : arr) cout << x << " ";
    return;
  }
  cout << -1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
