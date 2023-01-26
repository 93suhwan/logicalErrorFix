#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
inline int mrand(int k) { return abs((int)mt()) % k; }
template <typename X>
void debug(X x) {
  cerr << x << "] ";
}
template <typename X, typename... Y>
void debug(X x, Y... y) {
  cerr << x << " ";
  debug(y...);
}
void chemthan() {
  int n;
  cin >> n;
  vector<int> ispr(n + 1, 1);
  ispr[1] = 0;
  vector<int> prs;
  for (int i = (2); i < (n + 1); ++i)
    if (ispr[i]) {
      prs.push_back(i);
      for (int j = i + i; j <= n; j += i) {
        ispr[j] = 0;
      }
    }
  while (ispr[n]) n--;
  vector<long long> f(n + 1);
  for (int i = (0); i < (n + 1); ++i) f[i] = (long long)mrand() * mrand();
  vector<long long> g(n + 1);
  g[1] = 0;
  for (int i = (2); i < (n + 1); ++i)
    if (ispr[i]) {
      for (int j = i; j <= n; j += i) {
        int s = 0;
        for (long long t = i; t <= j; t *= i) {
          s ^= (j / t) & 1;
          s ^= ((j - 1) / t) & 1;
        }
        if (s) {
          g[j] ^= f[i];
        }
      }
    }
  for (int i = (1); i < (n + 1); ++i) g[i] ^= g[i - 1], f[i] = g[i];
  for (int i = (1); i < (n + 1); ++i) g[i] ^= g[i - 1];
  auto solve = [&]() {
    while (n) {
      if (!g[n]) {
        cout << n << "\n";
        for (int i = (1); i < (n + 1); ++i) cout << i << " \n"[i == n];
        return;
      }
      for (int i = (1); i < (n + 1); ++i)
        if (f[i] == g[n]) {
          vector<int> v;
          for (int j = (1); j < (n + 1); ++j)
            if (j != i) {
              v.push_back(j);
            }
          cout << int((v).size()) << "\n";
          for (int j = (0); j < (int((v).size())); ++j)
            cout << v[j] << " \n"[j == int((v).size()) - 1];
          return;
        }
      map<long long, int> mem;
      for (int i = (1); i < (n + 1); ++i) {
        auto t = f[i] ^ g[n];
        if (mem.count(t)) {
          int j = mem[t];
          vector<int> v;
          for (int k = (1); k < (n + 1); ++k)
            if (k != i && k != j) {
              v.push_back(k);
            }
          cout << int((v).size()) << "\n";
          for (int j = (0); j < (int((v).size())); ++j)
            cout << v[j] << " \n"[j == int((v).size()) - 1];
          return;
        }
        mem[f[i]] = i;
      }
      n--;
    }
  };
  solve();
}
int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
