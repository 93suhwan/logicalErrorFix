#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 9;
const long long INF = 1e12;
long long a[MAXN];
long long f[20][MAXN];
void init() {
  for (int i = 1; i < MAXN; i++) {
    a[i] = i;
  }
  for (int i = 1; i < MAXN; i++) {
    for (int j = i + i; j < MAXN; j += i) {
      a[j] -= a[i];
    }
  }
}
long long c(int l, int r) {
  long long ans = 0;
  int lst = 0;
  for (int i = l; i <= r; i = lst + 1) {
    lst = r / (r / i);
    ans += a[r / i] * (lst - i + 1ll);
  }
  return ans;
}
void work(long long *dpf, long long *dpg, int l, int r, int L, int R) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int opt = -1;
  long long cost = c(min(mid - 1, R) + 1, mid);
  for (int i = min(mid - 1, R); i >= L; i--) {
    long long newf = dpf[i] + cost;
    if (newf < dpg[mid]) {
      dpg[mid] = newf;
      opt = i;
    }
    cost += a[mid / i];
  }
  if (opt == -1) opt = L;
  work(dpf, dpg, l, (mid - 1), L, opt);
  work(dpf, dpg, (mid + 1), r, opt, R);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  for (int i = 1; i < MAXN; i++) {
    a[i] += a[i - 1];
  }
  int n = 10000;
  f[0][0] = 0;
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) {
    f[1][i] = 1ll * i * (i + 1) / 2;
  }
  for (int i = 1; i < 16; i++) {
    work(f[i], f[i + 1], 1, n, 1, n);
  }
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k >= 17) {
      cout << n << endl;
    } else {
      cout << f[k][n] << endl;
    }
  }
  return 0;
}
