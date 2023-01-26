#include <bits/stdc++.h>
using namespace std;
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
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
bool revsort(long long a, long long b) { return a > b; }
const int N = 2e5 + 5;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(5));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; j++) {
      int x;
      cin >> x;
      a[i][j] = x;
    }
  }
  int max = 0;
  for (int i = 1; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < 5; j++) {
      if (a[i][j] < a[max][j]) cnt++;
    }
    if (cnt >= 3) max = i;
  }
  int i;
  int res = -1;
  for (i = 0; i < n; ++i) {
    int cnt = 0;
    if (i != max) {
      for (int j = 0; j < 5; j++) {
        if (a[i][j] < a[max][j]) cnt++;
      }
      if (cnt >= 3) {
        res = -1;
        break;
      }
    }
  }
  if (i == n) res = max + 1;
  cout << res << '\n';
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
