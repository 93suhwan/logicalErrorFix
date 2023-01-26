#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
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
  cerr << "{ ";
  _print(p.first);
  cerr << " , ";
  _print(p.second);
  cerr << " }";
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
  cerr << "\n";
  for (auto i : v) {
    _print(i);
    cerr << "\n";
  }
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(long long a, long long b, long long* v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mminv(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(5));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 5; ++j) cin >> a[i][j];
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (i == j) continue;
      int cnti = 0, cntj = 0, cntij = 0;
      for (auto k : a) {
        if (k[i] == 1 and k[j] == 1)
          cntij++;
        else if (k[i] == 1)
          cnti++;
        else if (k[j] == 1)
          cntj++;
      }
      if (cnti < n / 2) cntij -= (n / 2 - cnti);
      if (cntj < n / 2) cntij -= (n / 2 - cntj);
      if (cntij >= 0) {
        cout << "YES\n";
        return;
      };
      ;
      cerr << endl;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) solve();
  return 0;
}
