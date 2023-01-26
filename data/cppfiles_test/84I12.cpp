#include <bits/stdc++.h>
using namespace std;
int T, n, k, cnt, p[110000], phi[110000];
long long f[20][110000], pre[110000];
bool vis[110000];
void init(int n) {
  vis[1] = 1;
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      p[++cnt] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
      vis[i * p[j]] = true;
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i * p[j]] = phi[i] * (p[j] - 1);
    }
  }
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + phi[i];
}
long long calc(int l, int r) {
  long long res = 0;
  for (int i = l, j; i <= r; i = j + 1) {
    j = r / (r / i);
    res += pre[r / i] * max(min(j, r) - i + 1, 0);
  }
  return res;
}
void solve(int l, int r, int x, int y) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  f[k][mid] = f[k - 1][mid];
  long long val = calc(x + 1, mid);
  int pos = mid;
  for (int i = x; i <= y && i < mid; i++) {
    if (f[k - 1][i] + val < f[k][mid]) {
      f[k][mid] = f[k - 1][i] + val;
      pos = i;
    }
    val -= pre[mid / (i + 1)];
  }
  solve(l, mid - 1, x, pos);
  solve(mid + 1, r, pos, y);
}
int main() {
  init(100000);
  memset(f[0], 0x3f, sizeof(f[0]));
  f[0][0] = 0;
  for (k = 1; k <= 17; k++) solve(1, 100000, 0, 99999);
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    if (k > 17) {
      printf("%d\n", n);
      continue;
    }
    printf("%lld\n", f[k][n]);
  }
  return 0;
}
