#include <bits/stdc++.h>
using namespace std;
long long mod = 999999937;
const long long INF = mod * mod;
const long double eps = 1e-8;
const long double pi = acosl(-1.0);
long long mod_pow(long long x, long long n, long long m = mod) {
  if (n < 0) {
    long long res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m) x %= m;
  if (x < 0) x += m;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
struct modint {
  long long n;
  modint() : n(0) { ; }
  modint(long long m) : n(m) {
    if (n >= mod)
      n %= mod;
    else if (n < 0)
      n = (n % mod + mod) % mod;
  }
  operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) {
  a.n += b.n;
  if (a.n >= mod) a.n -= mod;
  return a;
}
modint operator-=(modint& a, modint b) {
  a.n -= b.n;
  if (a.n < 0) a.n += mod;
  return a;
}
modint operator*=(modint& a, modint b) {
  a.n = ((long long)a.n * b.n) % mod;
  return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, long long n) {
  if (n == 0) return modint(1);
  modint res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}
long long inv(long long a, long long p) {
  return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) {
  a = a / b;
  return a;
}
const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = modint(1);
  for (int i = 0; i < max_n - 1; i++) {
    fact[i + 1] = fact[i] * modint(i + 1);
  }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1];
  for (int i = max_n - 2; i >= 0; i--) {
    factinv[i] = factinv[i + 1] * modint(i + 1);
  }
}
modint comb(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[a - b];
}
void expr(int n) {
  int ans = 0;
  vector<int> cur;
  function<void(int)> dfs = [&](int dep) {
    if (dep == n) {
      bool valid = true;
      for (int i = 0; i < cur.size(); i++) {
        int sum = 0;
        int mi = cur[i];
        int ma = cur[i];
        for (int j = i; j < cur.size(); j++) {
          sum += cur[j];
          mi = min(mi, cur[j]);
          ma = max(ma, cur[j]);
          if (mi * ma < sum) {
            valid = false;
          }
        }
      }
      if (valid) {
        ans++;
        for (int i = 0; i < cur.size(); i++) {
          cout << cur[i] << " ";
        }
        cout << "\n";
      }
      return;
    }
    for (int i = 2; i <= n + 1; i++) {
      cur.push_back(i);
      dfs(dep + 1);
      cur.pop_back();
    }
  };
  dfs(0);
  cout << ans << "\n";
}
void expr2(int n) {
  int ans = 0;
  vector<int> cur;
  function<void(int)> dfs = [&](int dep) {
    if (dep == n) {
      bool valid = true;
      int mi = cur[0];
      int ma = cur[0];
      int sum = 0;
      bool valid2 = true;
      for (int i = 0; i < cur.size(); i++) {
        int sum = 0;
        int mi = cur[i];
        int ma = cur[i];
        for (int j = i; j < cur.size(); j++) {
          sum += cur[j];
          mi = min(mi, cur[j]);
          ma = max(ma, cur[j]);
          if (mi * ma < sum) {
            valid2 = false;
          }
        }
      }
      for (int i = 0; i < cur.size(); i++) {
        mi = min(mi, cur[i]);
        ma = max(ma, cur[i]);
        sum += cur[i];
      }
      if (mi * ma < sum) {
        valid = false;
      }
      if (valid && !valid2) {
        ans++;
        for (int i = 0; i < cur.size(); i++) {
          cout << cur[i] << " ";
        }
        cout << "\n";
      }
      return;
    }
    for (int i = 2; i <= n + 1; i++) {
      cur.push_back(i);
      dfs(dep + 1);
      cur.pop_back();
    }
  };
  dfs(0);
  cout << ans << "\n";
}
modint dp[205][205];
modint pas[205][205];
void solve() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  mod = m;
  for (int i = 0; i < 205; i++)
    for (int j = 0; j < 205; j++) {
      if (i == 0 || j == 0)
        pas[i][j] = 1;
      else
        pas[i][j] = pas[i - 1][j] + pas[i][j - 1];
    }
  modint ans = 0;
  ans += mod_pow(2, n);
  for (int mi = 1; mi < n; mi++) {
    int x = 0;
    for (int len = mi + 1; len <= n; len++) {
      x += (len + 1) - mi;
    }
    if (x > mi) continue;
    for (int j = 0; j < n + 1; j++)
      for (int k = 0; k < mi + 1; k++) dp[j][k] = 0;
    for (int cnt = 1; cnt <= mi; cnt++) {
      dp[cnt][0] = 1;
    }
    for (int val = mi + 1; val <= n + 1; val++) {
      for (int j = val - 1; j >= 0; j--) {
        for (int k = mi + 1 - 1; k >= 0; k--) {
          if (dp[j][k] == (modint)0) continue;
          for (int ad = 1; j + ad < val; ad++) {
            int nj = j + ad;
            int nk = k + (val - mi) * ad;
            if (nk > mi) break;
            dp[nj][nk] += dp[j][k] * pas[ad][j];
          }
        }
      }
    }
    for (int k = 0; k < mi + 1; k++) ans += dp[n][k];
  }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
