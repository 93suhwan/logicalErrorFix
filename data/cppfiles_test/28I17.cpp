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
  }
  int cur = 0;
  vector<int> ans;
  for (int k = 0; k < n; k++) {
    int nop = n - shift[k];
    int req = (nop + 1) / 2;
    if (req <= m) ans.push_back(k);
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
