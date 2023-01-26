#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000005;
const long long SQRTN = 1003;
const long long LOGN = 22;
const double PI = acos(-1);
const long long INF = 1e16;
const long long MOD = 1000000007;
const long long FMOD = 998244353;
const double eps = 1e-9;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
long long add(long long a, long long b, long long c = MOD) {
  long long res = a + b;
  return (res >= c ? res - c : res);
}
long long mod_neg(long long a, long long b, long long c = MOD) {
  long long res;
  if (abs(a - b) < c)
    res = a - b;
  else
    res = (a - b) % c;
  return (res < 0 ? res + c : res);
}
long long mul(long long a, long long b, long long c = MOD) {
  long long res = (long long)a * b;
  return (res >= c ? res % c : res);
}
long long muln(long long a, long long b, long long c = MOD) {
  long long res = (long long)a * b;
  return ((res % c) + c) % c;
}
long long mulmod(long long a, long long b, long long m = MOD) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T expo(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T power(T e, T n, T m = MOD) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mul(x, p, m);
    p = mul(p, p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T extended_euclid(T a, T b, T& x, T& y) {
  T xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    T q = a / b, t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
template <typename T>
T mod_inverse(T a, T n = MOD) {
  T x, y, z = 0;
  T d = extended_euclid(a, n, x, y);
  return (d > 1 ? -1 : mod_neg(x, z, n));
}
const long long FACSZ = 1;
long long fact[FACSZ], ifact[FACSZ];
void precom(long long c = MOD) {
  fact[0] = 1;
  for (long long i = 1; i < FACSZ; i++) fact[i] = mul(fact[i - 1], i, c);
  ifact[FACSZ - 1] = mod_inverse(fact[FACSZ - 1], c);
  for (long long i = FACSZ - 1 - 1; i >= 0; i--) {
    ifact[i] = mul(i + 1, ifact[i + 1], c);
  }
}
long long ncr(long long n, long long r, long long c = MOD) {
  if (r > n) return 0;
  return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}
void solvethetestcase();
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long testcase = 1; testcase < t + 1; testcase++) {
    solvethetestcase();
  }
}
long long n, m;
long long a[505][505], sm[505][505];
vector<pair<long long, long long> > adj[505][505];
bool check() {
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      if (!a[i][j]) {
        long long cnt = 0;
        if (sm[i - 1][j] % 5) cnt += sm[i - 1][j];
        if (sm[i + 1][j] % 5) cnt += sm[i + 1][j];
        if (sm[i][j - 1] % 5) cnt += sm[i][j - 1];
        if (sm[i][j + 1] % 5) cnt += sm[i][j + 1];
        if (sm[i][j] != cnt) {
          return false;
        }
      }
    }
  }
  return true;
}
void dfs(long long i, long long j, long long c) {
  sm[i][j] = c;
  for (auto x : adj[i][j]) {
    if (sm[x.first][x.second] == 0) {
      dfs(x.first, x.second, 5 - c);
    }
  }
}
void solvethetestcase() {
  cin >> n >> m;
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      char c;
      cin >> c;
      a[i][j] = (c == '.');
    }
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      if (!a[i][j]) {
        long long cnt = a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
        if (cnt % 2) {
          cout << "NO\n";
          return;
        }
        if (cnt == 0) sm[i][j] = 0;
        if (cnt == 2) {
          sm[i][j] = 5;
          if (a[i - 1][j] and a[i + 1][j]) {
            adj[i - 1][j].push_back({i + 1, j});
            adj[i + 1][j].push_back({i - 1, j});
          }
          if (a[i - 1][j] and a[i][j - 1]) {
            adj[i - 1][j].push_back({i, j - 1});
            adj[i][j - 1].push_back({i - 1, j});
          }
          if (a[i - 1][j] and a[i][j + 1]) {
            adj[i - 1][j].push_back({i, j + 1});
            adj[i][j + 1].push_back({i - 1, j});
          }
          if (a[i + 1][j] and a[i][j - 1]) {
            adj[i + 1][j].push_back({i, j - 1});
            adj[i][j - 1].push_back({i + 1, j});
          }
          if (a[i + 1][j] and a[i][j + 1]) {
            adj[i + 1][j].push_back({i, j + 1});
            adj[i][j + 1].push_back({i + 1, j});
          }
          if (a[i][j - 1] and a[i][j + 1]) {
            adj[i][j - 1].push_back({i, j + 1});
            adj[i][j + 1].push_back({i, j - 1});
          }
        }
        if (cnt == 4) sm[i][j] = 10;
      }
    }
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      long long cnt = a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
      if (a[i][j] == 0 and cnt == 4) {
        vector<pair<long long, long long> > gg = {
            {i - 1, j}, {i, j - 1}, {i + 1, j}, {i - 1, j + 1}};
        while (true) {
          long long vis = 0;
          long long cur = 0;
          for (auto x : gg) {
            vis += (sm[x.first][x.second] == 0);
            cur += sm[x.first][x.second];
          }
          if (!vis) break;
          cur %= 5;
          if (cur <= 2) {
            for (auto x : gg) {
              if (sm[x.first][x.second] == 0) {
                dfs(x.first, x.second, 4);
                break;
              }
            }
          } else {
            for (auto x : gg) {
              if (sm[x.first][x.second] == 0) {
                dfs(x.first, x.second, 1);
                break;
              }
            }
          }
        }
      }
    }
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      if (sm[i][j] == 0 and a[i][j]) {
        dfs(i, j, 1);
      }
    }
  }
  if (check()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
    return;
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      cout << sm[i][j] << " ";
    }
    cout << "\n";
  }
}
