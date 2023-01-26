#include <bits/stdc++.h>
using namespace std;
struct Node {
  int x, pos;
} a[100005], b[100005];
const long long mod = 1e9 + 7;
namespace Comb {
const int N = 2e5 + 10;
long long F[N], invF[N], inv[N], bit[N];
void init() {
  F[0] = F[1] = inv[0] = inv[1] = invF[0] = invF[1] = 1;
  bit[0] = 1;
  bit[1] = 2;
  for (int i = 2; i < N; i++) {
    bit[i] = bit[i - 1] * 2 % mod;
    F[i] = F[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    invF[i] = invF[i - 1] * inv[i] % mod;
  }
}
long long C(long long m, long long n) {
  if (m < 0 || n < 0 || n > m) return 0;
  return F[m] * invF[n] % mod * invF[m - n] % mod;
}
}  // namespace Comb
namespace Prime {
const int N = 2e5 + 10;
int prime[N], cnt;
bool is_prime[N];
void init() {
  is_prime[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!is_prime[i]) prime[++cnt] = i;
    for (int p = 1; p <= cnt && i * prime[p] < N; p++) {
      is_prime[i * prime[p]] = 1;
      if (i % prime[p] == 0) break;
    }
  }
}
}  // namespace Prime
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  Comb::init();
  Prime::init();
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    int p, o;
    p = o = 0;
    for (int i = 1; i <= 10; i++) int t = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x & 1) {
        a[++p].x = x;
        a[p].pos = i;
      } else {
        b[++o].x = x;
        b[o].pos = i;
      }
    }
    if (abs(p - o) >= 2) {
      cout << -1 << endl;
      continue;
    }
    if (p > o) {
      int ans = 0;
      for (int i = 1; i <= 10; i++) int t = 0;
      for (int i = 1, k = 1; i <= n; i += 2, k++) ans += abs(a[k].pos - i);
      int c = 0;
      cout << ans << endl;
    } else if (o > p) {
      int ans = 0;
      for (int i = 1; i <= 10; i++) int t = 0;
      for (int i = 1, k = 1; i <= n; i += 2, k++) {
        int mx = 1e9;
        ans += abs(b[k].pos - i);
      }
      cout << ans << endl;
    } else {
      int ans1 = 0, ans2 = 0;
      for (int i = 1; i <= 10; i++) int t = 0;
      for (int i = 1, k = 1; i <= n; i += 2, k++) ans1 += abs(a[k].pos - i);
      for (int i = 1, k = 1; i <= n; i += 2, k++) ans2 += abs(b[k].pos - i);
      cout << min(ans1, ans2) << endl;
    }
  }
}
