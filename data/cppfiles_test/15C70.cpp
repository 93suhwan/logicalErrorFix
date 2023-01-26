#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 50;
const long long INF = 1e9;
long long dx[] = {-1, 0, 0, 1};
long long dy[] = {0, 1, -1, 0};
template <typename T>
void __print(long long x) {
  cerr << x;
}
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
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long mod = 998244353;
bool compare(const pair<long long, long long> &i,
             const pair<long long, long long> &j) {
  return i.second < j.second;
}
long long modexp(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return r % mod;
}
long long modinv(long long x) { return modexp(x, mod - 2); }
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
void google(long long t) { cout << "Case #" << t << ": "; }
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_sub(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a - b) % mod) + mod) % mod;
}
long long mod_div(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (mod_mul(a, modinv(b)) + mod) % mod;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  char A[n][m];
  bool vis[n][m];
  memset(vis, 1, sizeof(vis));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> A[i][j];
      if (A[i][j] == '*') vis[i][j] = 0;
    }
  }
  for (long long i = n - 1; i >= k; i--) {
    for (long long j = 0; j < m; j++) {
      if (A[i][j] == '*') {
        long long lvl = i - 1;
        long long l = j - 1, r = j + 1;
        long long cnt = 0;
        bool flag = 0;
        while (l >= 0 and r < m and lvl >= 0 and A[lvl][l] == '*' and
               A[lvl][r] == '*') {
          l -= 1;
          r += 1;
          lvl -= 1;
          cnt++;
        }
        l += 1;
        r -= 1;
        lvl += 1;
        if (cnt >= k) {
          while (cnt >= 0) {
            vis[lvl][l] = 1;
            vis[lvl][r] = 1;
            cnt--;
            lvl += 1;
            r -= 1;
            l += 1;
          }
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (!vis[i][j]) {
        cout << "NO"
             << "\n";
        return;
      }
    }
  }
  cout << "YES"
       << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) solve();
  return 0;
}
