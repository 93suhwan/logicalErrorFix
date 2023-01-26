#include <bits/stdc++.h>
using LL = long long;
const LL INF = 1e18;
const int N = 100100;
using namespace std;
int phi[N];
LL a[N];
LL dp[N][18];
LL c(int l, int r) {
  if (l > r) return INF;
  LL res = 0;
  for (int i = l; i <= r;) {
    int j = r / (r / i);
    res += (j - i + 1) * a[r / i];
    i = j + 1;
  }
  return res;
}
void dq(int k, int l, int r, int tl, int tr) {
  if (l > r) return;
  int m = l + r >> 1;
  dp[m][k] = INF;
  LL cost = c(tr + 1, m);
  int opt = m;
  for (int p = min(m, tr); p >= tl; p--) {
    LL cur = dp[p][k - 1] + cost;
    if (cur <= dp[m][k]) {
      dp[m][k] = cur;
      opt = p;
    }
    if (cost == INF) {
      cost = a[m / p];
    } else
      cost += a[m / p];
  }
  dq(k, l, m - 1, tl, opt);
  dq(k, m + 1, r, opt, tr);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 1e5;
  int k = 17;
  for (int i = 1; i <= n; i++) {
    phi[i] = i;
  }
  for (int i = 2; i <= n; i++)
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + phi[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1LL * i * (i + 1) / 2;
  }
  for (int j = 2; j <= k; j++) {
    dq(j, 1, n, 1, n);
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k > 17 || (1 << k) - 1 >= n) {
      cout << n << '\n';
      continue;
    }
    cout << dp[n][k] << '\n';
  }
}
