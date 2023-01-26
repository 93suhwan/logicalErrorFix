#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double PI = 2 * acos(0.0);
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
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
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
long long power(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    n = n / 2;
    x = x * x % mod;
  }
  return res % mod;
}
long long modinv(long long n) { return power(n, mod - 2); }
void solve() {
  long long n;
  cin >> n;
  long long i, a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  unordered_map<long long, long long> st;
  for (i = 0; i < n; i++) st[a[i]]++;
  long long j = 1;
  long long cnt = n / 2;
  while (j < n) {
    i = 0;
    while (i < j) {
      if (st[a[j] % a[i]] == 0) {
        cout << a[j] << " " << a[i] << endl;
        cnt--;
      }
      if (cnt == 0) {
        return;
      }
      i++;
    }
    j++;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
