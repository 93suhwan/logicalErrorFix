#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
template <typename A, typename B>
A min(A x, B y) {
  if (x < y) return x;
  return y;
}
template <typename A, typename B>
A max(A x, B y) {
  if (x > y) return x;
  return y;
}
template <typename D>
istream &operator>>(istream &in, vector<D> &arr) {
  for (auto &(x) : (arr)) cin >> x;
  return in;
}
template <typename D>
ostream &operator<<(ostream &in, vector<D> &arr) {
  for (auto &x : arr) in << x << " ";
  return in;
}
template <typename D, typename B>
ostream &operator<<(ostream &in, pair<D, B> &p) {
  in << p.first << " " << p.second << " ";
  return in;
}
template <typename D, typename B>
istream &operator>>(istream &in, pair<D, B> &p) {
  in >> p.first >> p.second;
  return in;
}
int modpow(long long, long long, int);
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
void solve(int tc) {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << (n + 1) / 2 << " " << (n - 1) / 2 << " " << 1 << " "
         << "\n";
    return;
  }
  n /= 2;
  if (n % 2 == 0) {
    cout << n - 1 << " " << n + 1 << " " << 1 << " "
         << "\n";
  } else {
    cout << n - 2 << " " << n + 2 << " " << 1 << " "
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int k = 1, t = 1;
  cin >> t;
  while (t--) solve(k++);
  return 0;
}
int modpow(long long a, long long b, int m = 1000000007) {
  long long res = 1;
  a %= m;
  if (a == 0) return a;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a *= a;
    a %= m;
    b >>= 1;
  }
  return res;
}
