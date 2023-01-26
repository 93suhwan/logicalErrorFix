#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int pri[maxn], h[maxn], cnt;
long long phi[maxn];
void init() {
  phi[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    if (!h[i]) pri[cnt++] = i, phi[i] = i - 1;
    for (int j = 0; j < cnt && pri[j] * i < maxn; ++j) {
      h[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = pri[j] * phi[i];
        break;
      }
      phi[i * pri[j]] = (pri[j] - 1) * phi[i];
    }
  }
  for (int i = 1; i < maxn; ++i) phi[i] += phi[i - 1];
}
struct node {
  int n, B, tot, vis;
  long long suf[660];
  int id1[331], id2[331];
  void init(int _n) {
    if (vis) return;
    vis = 1;
    n = _n;
    B = sqrt(n);
    tot = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
      int k = n / l;
      r = n / k;
      suf[++tot] = (long long)(r - l + 1) * phi[k];
      if (k <= B)
        id1[k] = tot;
      else
        id2[n / k] = tot;
    }
    for (int i = tot - 1; i >= 0; --i) suf[i] += suf[i + 1];
  }
  int id(int x) { return x <= B ? id1[x] : id2[n / x]; }
  long long qry(int l) {
    int k = n / l;
    int pos = id(k);
    int r = n / k;
    return suf[pos + 1] + (long long)(r - l + 1) * phi[k];
  }
} e[maxn];
long long dp[20][maxn];
const long long inf = 0x3f3f3f3f3f3f3f3f;
void sol(int l, int r, int L, int R, int cur, int pre) {
  if (l > r) return;
  int mid = (r + l) >> 1;
  int p = -1;
  dp[cur][mid] = inf;
  for (int i = L; i <= min(mid - 1, R); ++i) {
    long long res = dp[pre][i] + e[mid].qry(i + 1);
    if (p == -1 || dp[cur][mid] > res) {
      dp[cur][mid] = res;
      p = i;
    }
  }
  sol(l, mid - 1, L, p, cur, pre);
  sol(mid + 1, r, p, R, cur, pre);
}
int main() {
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  init();
  for (int i = 1; i < maxn; ++i) e[i].init(i);
  const int N = 1e5;
  for (int i = 1; i < 18; ++i) sol(1, N, 0, N - 1, i, i - 1);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k >= ceil(log2(n))) {
      printf("%d\n", n);
      continue;
    }
    printf("%lld\n", dp[k][n]);
  }
  return 0;
}
