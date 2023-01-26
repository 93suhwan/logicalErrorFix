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
long long n = 0;
const long long mod = 1e9 + 7;
long long tt = 0;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long m) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long cur = power(x, y / 2, m);
  cur = (cur % m * cur % m);
  if ((y & 1)) cur = (cur % m * x % m) % m;
  return cur;
}
long long modinv(long long x, long long m) { return power(x, m - 2, m) % m; }
void pre_solve() {}
void sol(long long tc) {
  stack<pair<char, bool> > st;
  string s, t;
  cin >> s >> t;
  if (t.size() == 0) {
    cout << "YES\n";
    return;
  }
  long long j = (long long)t.size() - 1, i = (long long)s.size() - 1;
  while (i >= 0 && j >= 0) {
    if (s[i] == t[j]) {
      i--;
      j--;
    } else {
      i -= 2;
    }
  }
  if (j == -1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    tt++;
    sol(tc);
  }
  return 0;
}
