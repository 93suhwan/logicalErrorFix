#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
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
  long long t;
  cin >> t;
  while (t--) {
    long long n, ans = 0, l;
    cin >> n;
    l = n / 2;
    vector<long long> v(n);
    unordered_set<long long> s;
    for (long long i = 0; (long long)i < n; i++) cin >> v[i], s.insert(v[i]);
    for (long long i = 0; (long long)i < n - 1; i++) {
      long long p1 = v[i], p2 = v[i + 1];
      long long k1 = v[i + 1], k2 = v[i];
      if (p1 != p2) {
        if (s.count(p1 % p2) == 0) {
          cout << p1 << " " << p2 << "\n";
          ans++;
        }
      }
      if (ans >= l) break;
      if (k1 != k2) {
        if (s.count(k1 % k2) == 0) {
          cout << k1 << " " << k2 << "\n";
          ans++;
        }
      }
      if (ans >= l) break;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}
