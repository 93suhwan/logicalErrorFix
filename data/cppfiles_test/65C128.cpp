#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int mul(long long x, int y) { return x * y % MOD; }
void selfmul(int &x, int y) { x = mul(x, y); }
int add(int x, int y) {
  if ((x += y) >= MOD) x -= MOD;
  return x;
}
void selfadd(int &x, int y) { x = add(x, y); }
int sub(int x, int y) {
  if ((x -= y) < 0) x += MOD;
  return x;
}
int mod(int x) {
  x %= MOD;
  if (x < 0) x += MOD;
  return x;
}
const int N = 55;
const int MAX = 1e5 + 1;
vector<int> prime;
bool isPrime[MAX];
int mobius[MAX];
int n, m, lef[N], rig[N];
int f[N][MAX], res;
void sieve() {
  memset(isPrime, true, sizeof isPrime);
  isPrime[0] = isPrime[1] = false;
  mobius[1] = 1;
  for (int i = 2; i < MAX; ++i) {
    if (isPrime[i]) {
      prime.push_back(i);
      mobius[i] = -1;
    }
    for (int j = 0; i * prime[j] < MAX; ++j) {
      isPrime[i * prime[j]] = false;
      if (i % prime[j]) {
        mobius[i * prime[j]] = mobius[i] * mobius[prime[j]];
      } else
        break;
    }
  }
}
int func(const vector<int> &lef, const vector<int> &rig, int lim) {
  int n = lef.size();
  for (int i = 0; i < n; ++i) {
    if (lef[i] > rig[i]) return 0;
  }
  for (int i = 0; i < n; ++i) {
    memset(f[i], 0, (lim + 1) * sizeof(int));
  }
  for (int i = lef[0]; i <= lim; ++i) {
    f[0][i] = min(i, rig[0]) - lef[0] + 1;
    selfadd(f[0][i], f[0][i - 1]);
  }
  for (int i = 1; i < n; ++i) {
    for (int j = lef[i] + 1; j <= lim; ++j) {
      f[i][j] = sub(f[i - 1][j - lef[i]], f[i - 1][j - min(j - 1, rig[i]) - 1]);
      selfadd(f[i][j], f[i][j - 1]);
    }
  }
  return f[n - 1][lim] - f[n - 1][lim - 1];
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  sieve();
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> lef[i] >> rig[i];
  }
  for (int d = 1; d <= m; ++d) {
    auto ceildiv = [&](int a, int b) { return a / b + bool(a % b); };
    vector<int> l, r;
    for (int i = 1; i <= n; ++i) {
      l.push_back(ceildiv(lef[i], d));
      r.push_back(rig[i] / d);
    }
    selfadd(res, mod(mobius[d] * func(l, r, m / d)));
  }
  cout << res;
  return 0;
}
