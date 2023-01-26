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
void solve(long long tc) {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n), b(n), x(n, 0), y(n, 0), c(n);
  long long d = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    c[i] = m;
    d += a[i];
    d -= b[i];
    if (c[i] > a[i]) {
      y[i] = c[i] - a[i];
      b[i] -= y[i];
      c[i] -= y[i];
      d += y[i];
    }
    if (c[i] > b[i]) {
      x[i] = c[i] - b[i];
      a[i] -= x[i];
      c[i] -= x[i];
      d -= x[i];
    }
  }
  for (long long i = 0; i < n; i++) {
    if (d == 0) {
      long long mid = c[i] / 2;
      x[i] += mid;
      y[i] += c[i] - mid;
      d -= mid;
      d += c[i] - mid;
    } else if (d > 0) {
      if (d >= c[i]) {
        x[i] += c[i];
        d -= c[i];
      } else {
        x[i] += d;
        c[i] -= d;
        d = 0;
        long long mid = c[i] / 2;
        x[i] += mid;
        y[i] += c[i] - mid;
        d -= mid;
        d += c[i] - mid;
      }
    } else {
      d = -1ll * d;
      if (d >= c[i]) {
        y[i] += c[i];
        d -= c[i];
        d = -1ll * d;
      } else {
        y[i] += d;
        c[i] -= d;
        d = 0;
        long long mid = c[i] / 2;
        x[i] += mid;
        y[i] += c[i] - mid;
        d -= mid;
        d += c[i] - mid;
      }
    }
  }
  cout << (d >= 0 ? d : -1ll * d);
  cout << "\n";
  ;
  for (long long i = 0; i < n; i++) {
    cout << x[i] << " " << y[i];
    cout << "\n";
    ;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long tc = 1; tc <= t; tc++) {
    solve(tc);
  }
  return 0;
}
