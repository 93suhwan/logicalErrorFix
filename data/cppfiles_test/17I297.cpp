#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MOD = 1e9 + 7;
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
void fastio(void);
bool comp(pair<int, int> l, pair<int, int> r) { return l.second < r.second; }
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    vector<int> tmp(5, 0);
    for (int j = 0; j < 5; j++) {
      cin >> tmp[j];
    }
    sort(tmp.begin(), tmp.end());
    int best = tmp[0] + tmp[1] + tmp[2];
    arr.push_back({i + 1, best});
  }
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  sort(arr.begin(), arr.end(), comp);
  ;
  if (arr[0].second != arr[1].second)
    cout << arr[0].first << "\n";
  else
    cout << -1 << "\n";
}
signed main() {
  fastio();
  auto start = clock();
  long long t;
  cin >> t;
  while (t--) {
    cerr << "Case #" << t + 1 << ":"
         << "\n";
    solve();
  }
  double used = (double)(clock() - start);
  used = (used * 1000) / CLOCKS_PER_SEC;
  cerr << fixed << setprecision(2) << used << " ms"
       << "\n";
  return 0;
}
void fastio(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
