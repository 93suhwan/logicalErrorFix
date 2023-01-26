#include <bits/stdc++.h>
using namespace std;
template <class T>
void _print(T a) {
  cerr << a;
}
template <class T>
void _print(vector<T> v) {
  cerr << "[";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(set<T> s) {
  cerr << "[";
  for (T i : s) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> s) {
  cerr << "[";
  for (T i : s) {
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
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
vector<long long int> ans;
void cc() {
  for (long long int i = 1; i <= 1666; i++) {
    if (i % 3 == 0 || i % 10 == 3) continue;
    ans.push_back(i);
  }
}
void solve() {
  long long int n;
  cin >> n;
  cout << ans[n - 1] << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cc();
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
