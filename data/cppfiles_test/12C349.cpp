#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long inf = 1e18;
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
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, -1, 0, 1};
void swap(long long &a, long long &b);
long long m_m(long long a, long long b, long long m);
long long fxp(long long a, long long b, long long m);
long long msum(long long a, long long b, long long m);
long long msub(long long a, long long b, long long m);
long long mpro(long long a, long long b, long long m);
void solve() {
  long long n, m, k, i, j;
  cin >> n >> m >> k;
  long long mnh = 0, mnv = 0;
  if (n & 1) {
    mnh = m / 2;
    if (k < mnh) {
      cout << "NO"
           << "\n";
      return;
    }
    k -= mnh;
    if (k & 1) {
      cout << "NO"
           << "\n";
      return;
    } else {
      cout << "YES"
           << "\n";
      return;
    }
  } else if (m & 1) {
    mnv = n / 2;
    long long avalh = ((n * m) / 2) - mnv;
    if (avalh < k) {
      cout << "NO"
           << "\n";
      return;
    }
    if (k & 1) {
      cout << "NO"
           << "\n";
      return;
    } else {
      cout << "YES"
           << "\n";
      return;
    }
  } else {
    if (k & 1) {
      cout << "NO"
           << "\n";
      return;
    } else {
      cout << "YES"
           << "\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("Error.txt", "w", stderr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
long long fxp(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b % 2 == 0) return fxp(m_m(a, a, m), b / 2, m);
  return m_m(fxp(a, b - 1, m), a, m);
}
long long m_m(long long a, long long b, long long m) {
  long long res = 0;
  a = a % m;
  while (b) {
    if (b & 1) {
      res += a;
      res = res % m;
    }
    a = (a * 2) % m;
    b = b / 2;
  }
  return res;
}
void swap(long long &a, long long &b) {
  long long t = a;
  a = b;
  b = t;
}
long long msum(long long a, long long b, long long m) {
  return ((a % m + b % m) + m) % m;
}
long long msub(long long a, long long b, long long m) {
  return ((a % m - b % m) + m) % m;
}
long long mpro(long long a, long long b, long long m) {
  return (((a % m) * (b % m) + m)) % m;
}
