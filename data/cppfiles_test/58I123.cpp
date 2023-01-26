#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
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
long long Power(long long n, long long x, long long mod) {
  long long ans = 1;
  while (x > 0) {
    if (x & 1) ans = (ans * n) % mod;
    n = (n * n) % mod;
    x = x >> 1;
  }
  return ans;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long getSum(long long n) {
  long long sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
long long myceil(long long n, long long x) {
  long long y;
  if (n % x == 0) {
    y = n / x;
    return y;
  } else {
    y = n / x + 1;
    return y;
  }
}
long long maxCountSameSUM(long long arr[], long long n) {
  unordered_map<long long, long long> M;
  for (long long i = 0; i < n - 1; i++)
    for (long long j = i + 1; j < n; j++) M[(arr[i] + arr[j])]++;
  long long max_count = 0;
  for (auto ele : M)
    if (max_count < ele.second) max_count = ele.second;
  return max_count;
}
long long md = 1e9 + 7;
vector<long long> fact, inv;
void inverse(long long n) {
  if (n >= inv.size()) {
    long long size = inv.size();
    size = size == 0 ? 1 : size;
    inv.resize(n + 1);
    inv[0] = 1;
    for (long long i = size; i <= n; i++) inv[i] = Power(fact[i], md - 2, md);
  }
}
void factorial(long long n) {
  if (n >= fact.size()) {
    long long size = fact.size();
    size = size == 0 ? 1 : size;
    fact.resize(n + 1);
    fact[0] = 1;
    for (long long i = size; i <= n; i++) fact[i] = (fact[i - 1] * i) % md;
  }
}
long long ncr(long long n, long long r) {
  return (((fact[n] * inv[r]) % md) * inv[n - r]) % md;
}
bool sortbysecdesc(const pair<long long, long long> &a,
                   const pair<long long, long long> &b) {
  return a.second > b.second;
}
long long SZ(string &v) { return v.length(); }
template <typename C>
long long SZ(C &v) {
  return v.size();
}
template <typename C>
void UNIQUE(vector<C> &v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}
template <typename T, typename U>
void maxa(T &a, U b) {
  a = max(a, b);
}
template <typename T, typename U>
void mina(T &a, U b) {
  a = min(a, b);
}
const long long INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
void run_testcase() {
  long long n;
  cin >> n;
  vector<string> s(2);
  for (long long i = 0; i < 2; i++) {
    cin >> s[i];
  }
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < n; j++) {
      if (s[i][j] == '0') {
        if (i == 0) {
          if (s[i + 1][j] == '1') {
            if ((j + 1 < n && s[i + 1][j + 1] == '1' && s[i][j + 1] == '1') ||
                j + 1 >= n) {
              if ((j - 1 >= 0 && s[i + 1][j - 1] == '1' &&
                   s[i][j - 1] == '1') ||
                  j - 1 < 0) {
                cout << "NO"
                     << "\n";
                return;
              }
            }
          }
        }
      }
    }
  }
  cout << "YES"
       << "\n";
  return;
}
void q2() {}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long test_case;
  cin >> test_case;
  while (test_case--) {
    run_testcase();
  }
  return 0;
}
