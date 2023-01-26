#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2005, mod = 1000000007;
long long n, m, V, ans;
long long tmp[6];
map<string, long long> mp;
map<long long, long long> val, f[6];
set<long long> s;
string str;
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return res;
}
signed main() {
  scanf("%lld%lld", &m, &n), V = ((1ll << m) - 1) % (mod - 1);
  mp["white"] = 0, mp["yellow"] = 1, mp["green"] = 2, mp["blue"] = 3,
  mp["red"] = 4, mp["orange"] = 5;
  for (long long i = 1, x; i <= n; i++)
    cin >> x >> str, val[x] = mp[str], f[val[x]][x] = 1, s.insert(x);
  while (!s.empty()) {
    long long x = *s.rbegin(), y = x / 2;
    V = (V - 1 + (mod - 1)) % (mod - 1);
    s.erase(x);
    if (x == 1) {
      for (long long i = 0; i < 6; i++) ans = (ans + f[i][1]) % mod;
      break;
    }
    for (long long i = 0; i < 6; i++) tmp[i] = 0;
    for (long long i = 0; i < 6; i++)
      for (long long j = 0; j < 6; j++)
        if (i != j && (i ^ 1) != j && i != (j ^ 1))
          tmp[j] = (tmp[j] + f[i][x]) % mod;
    if (s.find(y) == s.end()) {
      for (long long i = 0; i < 6; i++) f[i][y] = tmp[i];
      s.insert(y);
    } else
      for (long long i = 0; i < 6; i++) f[i][y] = 1ll * f[i][y] * tmp[i] % mod;
  }
  printf("%lld\n", 1ll * ans * ksm(4, V) % mod);
  return 0;
}
