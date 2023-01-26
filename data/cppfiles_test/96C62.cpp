#include <bits/stdc++.h>
using namespace std;
void show(vector<long long> &a) {
  for (long long e : a) {
    if (e == (long long)(1000000000000000000 + 5))
      cout << "INF ";
    else
      cout << e << " ";
  }
  cout << "\n";
}
void show(vector<int> &a) {
  for (int e : a) {
    if (e == (long long)(1000000000 + 7))
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
long long inline mo(long long a) { return a % (long long)(1000000000 + 7); }
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
const int maxn = 505;
long long fact[maxn];
long long C(long long x, long long y) {
  if (x < y) return 0;
  return (fact[x] *
          ((po(fact[y], (long long)(998244353) - 2, (long long)(998244353)) *
            po(fact[x - y], (long long)(998244353) - 2,
               (long long)(998244353))) %
           (long long)(998244353))) %
         (long long)(998244353);
}
long long dp[maxn][maxn];
long long rec(long long n, long long x) {
  if (n <= 0) return 1;
  long long &res = dp[n][x];
  if (res != -1) return res;
  if (x <= n - 1) return res = po(x, n, (long long)(998244353));
  res = 0;
  for (long long low = 0; low <= n; low++) {
    res += (((C(n, low) * po(n - 1, low, (long long)(998244353))) %
             (long long)(998244353)) *
            rec(n - low, x - (n - 1))) %
           (long long)(998244353);
    res %= (long long)(998244353);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  for (long long i = 1; i < maxn; i++)
    fact[i] = (fact[i - 1] * i) % (long long)(998244353);
  long long n, x;
  cin >> n >> x;
  for (long long i = 0; i < maxn; i++) {
    for (long long j = 0; j < maxn; j++) {
      dp[i][j] = -1;
    }
  }
  long long ans = rec(n, x);
  cout << ans << "\n";
  return 0;
}
