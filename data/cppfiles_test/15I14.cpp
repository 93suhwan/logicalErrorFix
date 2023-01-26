#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
long long int power(long long int x, unsigned long long int y) {
  long long res = 1, m = y + 2;
  x %= m;
  while (y > 0) {
    if (y & 1) res = res * x % m;
    x = x * x % m;
    y >>= 1;
  }
  return res;
}
long long int modInverse(long long int a, long long int m = MOD) {
  return power(a, m - 2);
}
struct comb {
  long long MAXA1;
  std::vector<long long> fac;
  comb(long long MAXA) {
    fac.resize(MAXA + 4);
    fac[0] = 1;
    MAXA1 = MAXA;
    for (long long i = 1; i <= MAXA; i++) {
      fac[i] = i * fac[i - 1] % MOD;
    }
  }
  long long ncr(long long n, long long r) {
    long long ans = 1;
    if (n < r) {
      cerr << "n is smaller than r"
           << "\n"
           << "\n";
      return 0;
    }
    if (n > MAXA1) {
      cerr << "Precalulate correctly with long vector size"
           << "\n"
           << "\n";
      assert(1 == 2);
    }
    ans = fac[n];
    ans *= modInverse(fac[n - r]);
    ans %= MOD;
    ans *= modInverse(fac[r]);
    ans %= MOD;
    return ans;
  }
  long long npr(long long n, long long r) {
    if (n < r) {
      cerr << "n is smaller than r"
           << "\n"
           << "\n";
      return 0;
    }
    if (n > MAXA1) {
      cerr << "Precalulate correctly with long vector size"
           << "\n"
           << "\n";
      assert(1 == 2);
    }
    long long ans = fac[n];
    ans *= modInverse(fac[n - r]);
    ans %= MOD;
    return ans;
  }
};
std::vector<long long int> v[104];
long long int d[104][104], mark[104];
void dfs(long long int in, long long int z, long long int dep) {
  long long int i, j;
  mark[in] = 1;
  d[z][in] = dep;
  dep++;
  for (auto x : v[in]) {
    if (!mark[x]) {
      dfs(x, z, dep);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  comb fac(1e3);
  long long int test = 1;
  cin >> test;
  while (test--) {
    long long int n, k, i, j;
    cin >> n >> k;
    for (i = 0; i < n + 1; i++) v[i].clear();
    for (i = 0; i < n - 1; i++) {
      long long int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    for (i = 1; i < n + 1; i++) {
      for (j = 0; j < n + 1; j++) mark[j] = 0;
      dfs(i, i, 0);
    }
    long long int ans = 0;
    std::map<long long int, long long int> m[104];
    for (i = 1; i < n + 1; i++) {
      for (j = 1; j < n + 1; j++) {
        m[i][d[i][j]]++;
      }
    }
    for (i = 0; i < n + 1; i++) {
      if (i & 1) continue;
      long long int x = i / 2;
      for (j = 1; j < n + 1; j++) {
        ans += fac.ncr(m[j][x], k);
        ans %= MOD;
      }
    }
    cout << ans << "\n";
  }
  cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms"
       << "\n";
  return 0;
}
