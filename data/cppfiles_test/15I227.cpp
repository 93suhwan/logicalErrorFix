#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<long long> init(string s) {
  istringstream sin(s);
  long long n;
  vector<long long> arr;
  while (sin >> n) arr.push_back(n);
  return arr;
}
inline long long powMod(long long a, long long b) {
  long long x = 1;
  while (b > 0) {
    if (b & 1) x = (x * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return x;
}
inline long long multiply(long long x, long long y) {
  return ((x % 1000000007) * (y % 1000000007)) % 1000000007;
}
inline long long divide(long long x, long long y) {
  return ((x % 1000000007) * powMod(y % 1000000007, 1000000007 - 2)) %
         1000000007;
}
inline long long ceil(long long a, long long b) { return (a + b - 1) / b; }
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long inverseMod(long long a, long long m) {
  a = a % m;
  for (ll x = 1; x < m; x++)
    if ((a * x) % m == 1) return x;
  return -1;
}
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
  cerr << "\n";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr << "\n";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr << "\n";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr << "\n";
}
template <long long D, typename T>
struct vec : public vector<vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  vec(long long n = 0, Args... args)
      : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template <typename T>
struct vec<1, T> : public vector<T> {
  vec(long long n = 0, T val = T()) : vector<T>(n, val) {}
};
bool valid(long long i, long long j, vec<2, bool> &mat) {
  long long n = mat.size();
  long long m = mat[0].size();
  return i >= 0 && i < n && j >= 0 && j < m && mat[i][j];
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vec<2, bool> mat(n, m, false), vis(n, m, false);
  vec<2, long long> maxh(n, m, -1);
  bool p = false;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      char x;
      cin >> x;
      if (x == '*') {
        p = true;
        mat[i][j] = true;
        vis[i][j] = true;
      }
    }
  }
  if (!p) cout << "YES\n";
  long long min_d = 11;
  for (long long i = n - 1; i >= 0; i--) {
    for (long long j = m - 1; j >= 0; j--) {
      if (mat[i][j]) {
        long long h = 0;
        while (true) {
          long long x = i - h;
          long long y1 = j - h;
          long long y2 = j + h;
          if (!valid(x, y1, mat) || !valid(x, y2, mat)) break;
          h++;
        }
        long long f_h = h - 1;
        h = 0;
        while (true) {
          long long x = i - h;
          long long y1 = j - h;
          long long y2 = j + h;
          if (!valid(x, y1, mat) || !valid(x, y2, mat)) break;
          maxh[x][y1] = max(f_h, maxh[x][y1]);
          maxh[x][y2] = max(f_h, maxh[x][y2]);
          h++;
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (maxh[i][j] != -1) {
        min_d = min(min_d, maxh[i][j]);
      }
    }
  };
  ;
  if (min_d >= k) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
