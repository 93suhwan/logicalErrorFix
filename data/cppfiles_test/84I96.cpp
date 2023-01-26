#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long dp[17][100005];
int pri[100005], tl, tr, B;
int get(int l, int r) {
  B = sqrt(r);
  int re = 0;
  for (int i = l; i <= B; i++) {
    re += 1 + 1ll * pri[r / i] * (pri[r / i] + 1) / 2;
  }
  l = max(l, B + 1);
  for (int i = 1; i <= B; i++) {
    tr = r / i, tl = r / (i + 1) + 1;
    tl = max(tl, l);
    if (tl <= tr) {
      re += (1 + 1ll * pri[i] * (pri[i] + 1) / 2) * (tr - tl + 1);
    }
  }
  return re;
}
void solve(int x, int l, int r, int tl, int tr) {
  if (l > r) return;
  int mid = (l + r) >> 1, tm = -1;
  long long now = get(tl, mid);
  dp[x][mid] = 1e18;
  for (int i = tl; i <= min(tr, mid); i++) {
    long long to = dp[x - 1][i - 1] + now;
    if (to < dp[x][mid]) {
      dp[x][mid] = to;
      tm = i;
    }
    now -= 1 + (1 + pri[mid / i]) * (1ll * pri[mid / i]) / 2;
  }
  solve(x, l, mid - 1, tl, tm);
  solve(x, mid + 1, r, tm, tr);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i <= 100000; i++) pri[i] = 1;
  for (int i = 2; i <= 100000; i++)
    if (pri[i]) {
      for (int j = i + i; j <= 100000; j += i) pri[j] = 0;
    }
  for (int i = 2; i <= 100000; i++) pri[i] = pri[i - 1] + pri[i];
  for (int i = 1; i <= 100000; i++) {
    dp[0][i] = 1e18;
  }
  for (int i = 1; i <= 16; i++) {
    solve(i, 1, 100000, 1, 100000);
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    if (y > 16) {
      cout << x << '\n';
    } else
      cout << dp[y][x] << '\n';
  }
  return 0;
}
