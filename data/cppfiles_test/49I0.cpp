#include <bits/stdc++.h>
using namespace std;
long long mulMod(long long a, long long b, long long m = 1000000007) {
  long long x = 0, y = a % m;
  while (b > 0) {
    if (b % 2 == 1) x = (x + y) % m;
    y = (y * 2) % m;
    b /= 2;
  }
  return x % m;
}
long long expMod(long long b, long long e, long long m = 1000000007) {
  if (!e) return 1;
  long long q = expMod(b, e / 2, m);
  q = mulMod(q, q, m);
  return e % 2 ? mulMod(b, q, m) : q;
}
long long invFact[20], fact[20];
long long inverso(long long x) { return expMod(x, 1000000007 - 2); }
void pre() {
  fact[0] = 1;
  for (int i = (1); i < (20 - 2); i++) fact[i] = (fact[i - 1] * i) % 1000000007;
  invFact[20 - 3] = inverso(fact[20 - 3]);
  for (int i = 20 - 3 - 1; i >= 0; i--)
    invFact[i] = (invFact[i + 1] * (i + 1)) % 1000000007;
  return;
}
long long comb(long long nn, long long k) {
  if (k < 0 || nn < k) return 0;
  return (fact[nn] * invFact[k] % 1000000007) * invFact[nn - k] % 1000000007;
}
int n;
long long win[15][15];
long long get(int mask1, int mask2) {
  long long ret = 1;
  for (int i = (0); i < (n); i++) {
    if ((mask1 >> i) & 1) {
      for (int j = (0); j < (n); j++) {
        if ((mask2 >> j) & 1) {
          ret = ((ret * win[i][j] % 1000000007) + 1000000007) % 1000000007;
          assert(ret >= 0);
        }
      }
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  vector<long long> a(n);
  for (int i = (0); i < (n); i++) cin >> a[i];
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (n); j++)
      win[i][j] = (((a[i] * inverso(a[i] + a[j])) % 1000000007) + 1000000007) %
                  1000000007;
  vector<long long> proba(1 << n, 1);
  long long rta = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int submask = mask & (mask - 1); submask;
         submask = (submask - 1) & mask) {
      proba[mask] -= proba[submask] * get(submask, mask ^ submask);
      proba[mask] = ((proba[mask] % 1000000007) + 1000000007) % 1000000007;
      assert(proba[mask] >= 0);
    }
    rta += (__builtin_popcount(mask) * proba[mask] *
            get(mask, ((1 << n) - 1) ^ mask)) %
           1000000007;
    rta = ((rta % 1000000007) + 1000000007) % 1000000007;
  }
  cout << rta << '\n';
  return 0;
}
