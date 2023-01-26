#include <bits/stdc++.h>
using namespace std;
void show(vector<long long> &a) {
  for (long long e : a) {
    if (e == (long long)(1e18 + 5))
      cout << "INF ";
    else
      cout << e << " ";
  }
  cout << "\n";
}
void show(vector<int> &a) {
  for (int e : a) {
    if (e == (long long)(1e9 + 7))
      cout << "MOD ";
    else
      cout << e << " ";
  }
  cout << "\n";
}
template <typename T>
void enter(vector<T> &a) {
  for (T &e : a) cin >> e;
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void JUDGE() {}
long long inline mo(long long a) { return a % (long long)(1e9 + 7); }
long long po(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> a(n, vector<long long>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      a[i][j] = (ch == '.');
    }
  }
  vector<vector<long long>> ex(n, vector<long long>(m));
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j < m; j++) {
      if (a[i][j]) {
        if (!a[i - 1][j] && !a[i][j - 1]) {
          ex[i][j] = 1;
        }
      }
    }
  }
  vector<long long> sum(m);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      sum[j] += ex[i][j];
    }
  }
  long long q;
  cin >> q;
  for (long long i = 1; i < m; i++) sum[i] += sum[i - 1];
  while (q--) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    long long val = sum[r] - sum[l];
    if (val) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
