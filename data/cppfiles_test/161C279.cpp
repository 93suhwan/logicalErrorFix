#include <bits/stdc++.h>
using namespace std;
template <class T>
void _print(T t) {
  cerr << t;
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
void _print(vector<T> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(queue<T> v) {
  cerr << "[ ";
  while (!v.empty()) {
    _print(v.front());
    cerr << " ";
    v.pop();
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
template <class T>
void read(vector<T> &v) {
  for (auto &i : v) cin >> i;
}
template <class T>
void show(vector<T> v) {
  for (auto i : v) cout << i << ' ';
  cout << '\n';
}
template <class T>
void read2(vector<vector<T>> &v) {
  for (auto &row : v) {
    for (auto &it : row) cin >> it;
  }
}
template <class T>
void show2(vector<vector<T>> v) {
  for (auto row : v) {
    for (auto it : row) cout << it << ' ';
    cout << '\n';
  }
}
void foo(long long l, long long r, long long d) {
  cout << l << ' ' << r << ' ' << d << '\n';
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  for (long long i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    v[i] = {l, r};
  }
  sort(v.begin(), v.end(),
       [&](pair<long long, long long> a, pair<long long, long long> b) {
         if (a.first == b.first) return a.second > b.second;
         return a.first < b.first;
       });
  for (long long i = 0; i < n - 1; i++) {
    if (v[i].first == v[i].second) {
      foo(v[i].first, v[i].second, v[i].first);
      continue;
    }
    if (v[i].first != v[i + 1].first) {
      foo(v[i].first, v[i].second, v[i].first);
      continue;
    }
    if (v[i].second != v[i + 1].second) {
      foo(v[i].first, v[i].second, v[i + 1].second + 1);
      continue;
    }
  }
  foo(v.back().first, v.back().second, v.back().first);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_cases;
  cin >> test_cases;
  while (test_cases--) solve();
  return 0;
}
