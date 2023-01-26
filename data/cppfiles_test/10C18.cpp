#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 2e6 + 10;
const int mod = 1e9 + 7;
long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long inv(long long a) { return ksm(a, mod - 2); }
int not_prime[maxn], prime[maxn], tot;
void phii() {
  for (int i = 2; i <= maxn; i++) {
    if (!not_prime[i]) prime[++tot] = i;
    for (int j = 1; j <= tot && prime[j] * i <= maxn; j++) {
      not_prime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
signed main() {
  long long n, m, k, r, c, A, B, C, D;
  cin >> n >> m >> k >> r >> c;
  cin >> A >> B >> C >> D;
  if (A == C && B == D)
    cout << ksm(k, n * m) << endl;
  else
    cout << ksm(k, n * m - r * c) << endl;
  return 0;
}
