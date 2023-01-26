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
void chemthan() {
  int C = 1e5 + 5;
  vector<int> sp(C);
  for (int i = (1); i < (C); ++i) sp[i] = i;
  for (int i = (2); i < (C); ++i)
    if (sp[i] == i) {
      for (int j = i + i; j < C; j += i) {
        chkmin(sp[j], i);
      }
    }
  vector<int> mob(C, 1);
  for (int i = (2); i < (C); ++i) {
    int t = i;
    int pv = -1;
    while (1 < t) {
      if (pv == sp[t]) {
        mob[i] = 0;
      }
      mob[i] *= -1;
      pv = sp[t];
      t /= sp[t];
    }
  }
  vector<vector<int> > dvs(C);
  vector<vector<int> > dvs2(C);
  for (int i = (1); i < (C); ++i) {
    for (int j = i; j < C; j += i) {
      dvs[j].push_back(i);
      if (mob[j / i]) dvs2[j].push_back(i);
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int> > g(C);
  for (int i = (0); i < (n); ++i) {
    cin >> a[i];
    for (int d : dvs[i + 1]) {
      g[d].push_back(a[i]);
    }
  }
  vector<int> c(C);
  vector<int> f(C);
  vector<int> x(C);
  vector<int> y(C);
  int res = 0;
  for (int i = (1); i < (C); ++i)
    if (int((g[i]).size())) {
      vector<int> tmp2;
      vector<int> tmp;
      for (int u : g[i]) {
        c[u] = 0;
      }
      for (int u : g[i]) {
        if (!c[u]++) {
          tmp2.push_back(u);
        }
      }
      for (int u : tmp2) {
        for (int d : dvs[u]) {
          if (!f[d]) {
            tmp.push_back(d);
          }
          f[d] += c[u];
        }
      }
      for (int u : tmp) {
        f[u] = mult(f[u], f[u]);
      }
      int sum = 0;
      for (int u : tmp) {
        for (int v : dvs2[u]) {
          if (mob[u / v]) {
            if (mob[u / v] == 1) {
              addmod(x[v], f[u]);
            } else {
              submod(x[v], f[u]);
            }
          }
        }
      }
      for (int u : tmp) {
        addmod(sum, mult(x[u], u));
      }
      y[i] = sum;
      for (int u : tmp) f[u] = x[u] = 0;
    }
  for (int i = (C)-1; i >= (1); --i) {
    for (int j = i + i; j < C; j += i) {
      submod(y[i], y[j]);
    }
    addmod(res, mult(i, y[i]));
  }
  cout << res << "\n";
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
