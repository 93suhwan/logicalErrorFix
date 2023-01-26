#include <bits/stdc++.h>
using namespace std;
long long int ivalue(string s) {
  long long int x = 0;
  stringstream obj(s);
  obj >> x;
  return x;
}
const long long int M = 1e9 + 7;
const long long int N = 1e5 + 5;
const long long int inf = 2e18;
long long int mod(long long int x) { return (x % M); }
long long int mod_minus(long long int a, long long int b) {
  long long int ans = (mod(a) - mod(b));
  if (ans < 0) ans = mod(ans + M);
  return ans;
}
long long int mod_mul(long long int a, long long int b) {
  return mod(mod(a) * mod(b));
}
long long int mod_add(long long int a, long long int b) {
  return mod(mod(a) + mod(b));
}
long long int power(long long int a, long long int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return a;
  long long int R = power(a, n / 2) % M;
  if (n % 2 == 0) {
    return mod(mod_mul(R, R));
  } else {
    return mod(mod_mul(mod_mul(R, a), mod(R)));
  }
}
long long int mod_div(long long int a, long long int b) {
  long long int ans = mod(a);
  long long int b1 = power(b, M - 2);
  ans = mod(mod_mul(ans, b1));
  return ans;
}
long long int mod_inv(long long int n) { return power(n, M - 2); }
long long int fact_mod(long long int n) {
  vector<long long int> fact(n + 1);
  fact[0] = 1;
  for (long long int i = 1; i < n + 1; i++) {
    fact[i] = mod_mul(fact[i - 1], i);
  }
  return fact[n];
}
long long int nCr_mod(long long int n, long long int r) {
  if (r == 0 || n == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % M;
  return (fac[n] * mod_inv(fac[r]) % M * mod_inv(fac[n - r]) % M) % M;
}
long long int upper_fraction(long long int a, long long int b) {
  if (a % b == 0)
    return a / b;
  else
    return (a / b) + 1;
}
bool isInt(double d) {
  double dummy;
  return modf(d, &dummy) == 0.0;
}
void solve() {
  long long int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  long long int i;
  string temp;
  vector<vector<long long int> > dp(4, vector<long long int>(n + 1, 0));
  for (i = 0; i < n; i++) {
    if (i % 2) {
      if (s[i] == '+') {
        dp[2][i + 1] = dp[2][i] + 1;
        dp[1][i + 1] = dp[1][i];
        dp[3][i + 1] = dp[3][i];
        dp[0][i + 1] = dp[0][i];
      } else {
        dp[3][i + 1] = dp[3][i] + 1;
        dp[1][i + 1] = dp[1][i];
        dp[2][i + 1] = dp[2][i];
        dp[0][i + 1] = dp[0][i];
      }
    } else {
      if (s[i] == '+') {
        dp[0][i + 1] = dp[0][i] + 1;
        dp[1][i + 1] = dp[1][i];
        dp[2][i + 1] = dp[2][i];
        dp[3][i + 1] = dp[3][i];
      } else {
        dp[1][i + 1] = dp[1][i] + 1;
        dp[3][i + 1] = dp[3][i];
        dp[2][i + 1] = dp[2][i];
        dp[0][i + 1] = dp[0][i];
      }
    }
  }
  while (q--) {
    long long int u, v;
    cin >> u >> v;
    if (u == v) {
      cout << 1 << endl;
      continue;
    }
    long long int ev_plus = dp[0][v] - dp[0][u - 1];
    long long int ev_min = dp[1][v] - dp[1][u - 1];
    long long int od_plus = dp[2][v] - dp[2][u - 1];
    long long int od_min = dp[3][v] - dp[3][u - 1];
    if (ev_plus + od_min == od_plus + ev_min)
      cout << 0 << endl;
    else if ((v - u + 1) % 2 != 0)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}
