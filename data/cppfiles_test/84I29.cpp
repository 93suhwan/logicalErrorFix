#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1ll << 60;
const int N = 1e5 + 20, K = 21;
long long int dp[K][N];
int T, tot, pri[N], tag[N], s[N], n = 100000, k = 20;
long long int calc(int x, int y, long long int out = 0) {
  for (int l = x, r; l <= y; l = r + 1)
    r = y / (y / l), out += 1ll * (r - l + 1) * s[y / l];
  return out;
}
inline void solve(int p, int L, int R, int ql, int qr) {
  int mid = L + R >> 1, q, r = min(mid, qr);
  long long int &out = dp[p][mid], v, c = calc(ql, mid);
  out = INF;
  for (int i = ql; i <= r; i++) {
    v = dp[p - 1][i - 1] + c, c -= s[mid / i];
    if (v <= out) out = v, q = i;
  }
  if (L != R) solve(p, L, mid, ql, q), solve(p, mid + 1, R, q, qr);
}
int main() {
  for (int i = 2; i <= n; i++) {
    if (!tag[i]) pri[++tot] = i, s[i] = i - 1;
    for (int j = 1; j <= tot; j++) {
      if (i * pri[j] > n) break;
      tag[i * pri[j]] = 1, s[i * pri[j]] = s[i] * (pri[j] - 1);
      if (i % pri[j] == 0) {
        s[i * pri[j]] += s[i];
        break;
      }
    }
  }
  s[1] = 1;
  for (int i = 1; i <= n; i++) s[i] += s[i - 1], dp[0][i] = INF;
  for (int i = 1; i <= k; i++) solve(i, 1, n, 1, n);
  for (scanf("%d", &T); T--;)
    if (scanf("%d%d", &n, &k), k >= K)
      cout << n << '\n';
    else
      cout << dp[k][n] << '\n';
  return 0;
}
