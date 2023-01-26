#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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
void fastio(void);
long long fast_pow(long long a, long long p) {
  long long res = 1ll;
  while (p) {
    if (p % 2ll == 0ll) {
      a = a * 1ll * a;
      p /= 2ll;
    } else {
      res = res * 1ll * a;
      p--;
    }
  }
  return res;
}
int fact(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % 1000000007;
  }
  return res;
}
int nCr(int n, int k) {
  return fact(n) * 1ll * fast_pow(fact(k), 1000000007 - 2) % 1000000007 * 1ll *
         fast_pow(fact(n - k), 1000000007 - 2) % 1000000007;
}
void solve() {
  long long w, h;
  cin >> w >> h;
  long long n;
  long long a, b;
  long long f, l;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    if (i == 0)
      cin >> f;
    else if (i == n - 1)
      cin >> l;
    else
      cin >> tmp;
  }
  a = l - f;
  ;
  ;
  ;
  ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    if (i == 0)
      cin >> f;
    else if (i == n - 1)
      cin >> l;
    else
      cin >> tmp;
  }
  a = max(a, l - f);
  ;
  ;
  ;
  ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    if (i == 0)
      cin >> f;
    else if (i == n - 1)
      cin >> l;
    else
      cin >> tmp;
  }
  b = l - f;
  ;
  ;
  ;
  ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    if (i == 0)
      cin >> f;
    else if (i == n - 1)
      cin >> l;
    else
      cin >> tmp;
  }
  b = max(b, l - f);
  ;
  ;
  ;
  ;
  long long ans = max(a * h, w * b);
  cout << ans << "\n";
}
signed main(int argc, char *argv[]) {
  fastio();
  int t = 1;
  cin >> t;
  while (t--) {
    ;
    solve();
  }
  return 0;
}
void fastio(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
