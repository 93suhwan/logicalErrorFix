#include <bits/stdc++.h>
using namespace std;
void _print(long long w) { cerr << w; }
void _print(int w) { cerr << w; }
void _print(string w) { cerr << w; }
void _print(char w) { cerr << w; }
void _print(long double w) { cerr << w; }
void _print(double w) { cerr << w; }
void _print(unsigned long long w) { cerr << w; }
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
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve() {
  int m, n, x;
  cin >> m >> n;
  vector<int> v[m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cin >> x, v[i].push_back(x);
  }
  vector<int> mx(n, -1);
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      mx[j] = max(mx[j], v[i][j]);
    }
  }
  int val1 = -INF;
  for (int i = 0; i < m; i++)
    sort(v[i].begin(), v[i].end(), greater<int>()), val1 = max(val1, v[i][1]);
  int val2 = INF;
  for (int j = 0; j < n; j++) val2 = min(val2, mx[j]);
  cout << min(val1, val2) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
