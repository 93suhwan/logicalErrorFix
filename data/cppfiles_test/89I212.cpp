#include <bits/stdc++.h>
using namespace std;
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
  int f = 0;
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
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
long long mod1 = 1000000007;
const long long INF = 1e18;
const long double pi = 3.14159265358979323846;
long long n, m, k, q, l, r, x, y, z;
const long long template_array_size = 200005;
long long a[template_array_size];
long long b[template_array_size];
long long c[template_array_size];
string s, t;
long long ans = 0;
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
namespace number_theory {
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  if (y == 0) return x;
  return gcd(y, x % y);
}
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool prime[15000105];
void sieve(int n) {
  for (long long i = 0; i <= n; i++) prime[i] = 1;
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  prime[1] = prime[0] = 0;
}
vector<long long> primelist;
bool __primes_generated__ = 0;
void genprimes(int n) {
  __primes_generated__ = 1;
  sieve(n + 1);
  for (long long i = 2; i <= n; i++)
    if (prime[i]) primelist.push_back(i);
}
vector<long long> factors(long long n) {
  if (!__primes_generated__) {
    cerr << "Call genprimes you dope" << endl;
    exit(1);
  }
  vector<long long> facs;
  for (long long i = 0;
       primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
    if (n % primelist[i] == 0) {
      while (n % primelist[i] == 0) {
        n /= primelist[i];
        facs.push_back(primelist[i]);
      }
    }
  }
  if (n > 1) {
    facs.push_back(n);
  }
  sort(facs.begin(), facs.end());
  return facs;
}
vector<long long> getdivs(long long n, long long k) {
  vector<long long> divs;
  for (long long i = 2; i <= k; i++) {
    if (n % i == 0) {
      divs.push_back(i);
    }
  }
  {
    sort(divs.begin(), divs.end());
    divs.erase(unique(divs.begin(), divs.end()), divs.end());
  };
  return divs;
}
}  // namespace number_theory
using namespace number_theory;
int solve() {
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) cin >> b[i];
  vector<vector<long long>> divs;
  for (int i = 0; i < (int)(n); ++i) {
    bool ok = true;
    for (int j = 2; j <= min(20, i + 2); j++) {
      ok &= !(b[i] % j);
    }
    if (ok) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  q = 1;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
