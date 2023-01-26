#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(vector<vector<T>> v);
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
    cerr << " , ";
  }
  cerr << "]";
}
template <class T>
void _print(vector<vector<T>> v) {
  cerr << "[ ";
  for (auto& row : v) {
    cerr << " {";
    for (auto& col : row) {
      _print(col);
      cerr << " , ";
    }
    cerr << "}\n";
  }
  cerr << " ]";
}
const long long int no = 2e5 + 5, modulo = 998244353, inf = 1e18, N = 2e3 + 9;
long long int ar[no], br[no], cr[no];
long long int calc(long long int n) {
  if (n == 0) return 1;
  return (n * calc(n - 1)) % modulo;
}
long long int calc1(long long int n, long long int x) {
  if (n == 0) return 1;
  if (n == x)
    return calc1(n - 1, x) % modulo;
  else
    return (n * calc1(n - 1, x)) % modulo;
}
void solve() {
  long long int n = 0, m = 0, a = 0, b = 0, c = 0, d = 0, x = 0, y = 0, z = 0,
                w = 0, k = 0;
  cin >> n;
  for (long long int i = 0; i < n; i += 1) cin >> ar[i];
  sort(ar, ar + n);
  if (ar[n - 1] - ar[n - 2] > 1) {
    cout << 0 << "\n";
    return;
  }
  if (ar[n - 1] == ar[n - 2]) {
    cout << calc(n) << "\n";
    return;
  }
  for (long long int i = 0; i < n; i += 1) {
    if (ar[n - 2] == ar[i]) {
      x = i;
      break;
    }
  }
  y = calc1(n, n - x);
  cout << (y * (n - x - 1)) % modulo << "\n";
}
inline void runn() {}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  runn();
  long long int t = 1;
  cout << fixed << setprecision(15);
  cin >> t;
  for (long long int i = 1; i < t + 1; i += 1) {
    solve();
  }
}
