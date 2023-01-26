#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using namespace std;
long long gcd(long long i, long long j) {
  if (j == 0)
    return i;
  else
    return gcd(j, i % j);
}
template <typename T>
inline T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
const long long INF = 1e18 + 100;
const long double eps = 1e-11, pi = acos(-1);
const long long maxN = 1 << 20, maxT = 3010, A = 10, K = 420;
mt19937 mt_rand(time(0));
vector<int> mod = {500000003, 1000001137, 1500000041};
const int mod_sz = 3;
void panic() {
  cout << "No solution\n";
  exit(0);
}
bool is_it_prime(long long v) {
  for (long long i = 2; i * i <= v; ++i)
    if (v % i == 0) return false;
  return true;
}
long long gen_mod(int md) {
  while (!is_it_prime(md)) ++md;
  return md;
}
long long pw[mod_sz][maxN];
void build() {
  for (int i = 0; i < mod_sz; ++i) {
    pw[i][0] = 1;
  }
  for (int j = 1; j < maxN; ++j) {
    for (int i = 0; i < mod_sz; ++i) {
      pw[i][j] = pw[i][j - 1] * A % mod[i];
    }
  }
}
struct hs {
  vector<vector<long long>> h;
  int n;
  hs(string s) {
    n = s.length();
    h.assign(mod_sz, vector<long long>(n + 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < mod_sz; ++j) {
        h[j][i + 1] = (h[j][i] * A + s[i] - '0') % mod[j];
      }
    }
  }
  vector<long long> get(int l, int r) {
    vector<long long> res(mod_sz);
    for (int j = 0; j < mod_sz; ++j) {
      res[j] = (h[j][r] - h[j][l] * pw[j][r - l] % mod[j] + mod[j]) % mod[j];
    }
    return res;
  }
};
hs read() {
  string t;
  cin >> t;
  return hs(t);
}
vector<long long> operator+(vector<long long> a, vector<long long> b) {
  for (int j = 0; j < mod_sz; ++j) {
    a[j] = (a[j] + b[j]);
    if (a[j] >= mod[j]) a[j] -= mod[j];
  }
  return a;
}
void solve() {
  build();
  hs s = read();
  hs x = read();
  vector<long long> fin = x.get(0, x.n);
  for (int i = 0; i + 2 * (x.n - 1) <= s.n; ++i) {
    if (s.get(i, i + x.n - 1) + s.get(i + x.n - 1, i + 2 * (x.n - 1)) == fin) {
      cout << i + 1 << " " << i + x.n - 1 << "\n"
           << i + x.n << " " << i + 2 * (x.n - 1) << "\n";
      return;
    }
  }
  for (int i = 0; i + x.n <= s.n; ++i) {
    int b = 0, e = x.n + 1;
    while (b + 1 != e) {
      int m = (b + e) / 2;
      if (s.get(i, i + m) == x.get(0, m))
        b = m;
      else
        e = m;
    }
    int lcp = b;
    int l = i, r = i + x.n;
    for (int need = x.n - lcp, cnt = 0; need > 0 && cnt < 2; ++cnt, --need) {
      if (i >= need) {
        if (s.get(i - need, i) + s.get(i, i + x.n) == fin) {
          cout << i - need + 1 << " " << i << "\n"
               << i + 1 << " " << i + x.n << "\n";
          return;
        }
      }
      if (i + x.n + need <= s.n) {
        vector<long long> a = s.get(i, i + x.n),
                          b = s.get(i + x.n, i + x.n + need);
        if (s.get(i, i + x.n) + s.get(i + x.n, i + x.n + need) == fin) {
          cout << i + 1 << " " << i + x.n << "\n"
               << i + x.n + 1 << " " << i + x.n + need << "\n";
          return;
        }
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  srand(time(0));
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
