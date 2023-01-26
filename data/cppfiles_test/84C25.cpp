#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const long long inf = 1ll << 60;
bool p[N + 5];
int np[N + 5], ps;
long long val[N + 5];
void prep() {
  p[0] = p[1] = 1;
  val[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!p[i]) val[np[++ps] = i] = i - 1;
    for (int j = 1; i * np[j] <= N; j++) {
      p[i * np[j]] = 1;
      if (i % np[j])
        val[i * np[j]] = val[i] * (np[j] - 1);
      else {
        val[i * np[j]] = val[i] * np[j];
        break;
      }
    }
  }
  for (int i = 2; i <= N; i++) val[i] += val[i - 1];
}
int T;
long long f[20][N + 5];
long long s[N + 5];
void solve(int l, int r, int opl, int opr, int k) {
  if (l > r) return;
  int mid = (l + r) >> 1, op;
  if (opr < mid) {
    s[opr + 1] = 0;
    for (int l = opr + 1, r; l <= mid; l = r + 1) {
      r = mid / (mid / l);
      s[opr + 1] += val[mid / l] * (r - l + 1);
    }
  } else
    s[mid] = 1;
  for (int i = min(mid - 1, opr); i >= opl; i--) s[i] = s[i + 1] + val[mid / i];
  f[k][mid] = inf;
  for (int i = opl; i <= min(mid - 1, opr); i++)
    if (f[k - 1][i] + s[i + 1] <= f[k][mid]) {
      f[k][mid] = f[k - 1][i] + s[i + 1];
      op = i;
    }
  solve(l, mid - 1, opl, op, k);
  solve(mid + 1, r, op, opr, k);
}
int main() {
  prep();
  for (int i = 1; i <= N; i++) f[1][i] = 1ll * i * (i + 1) / 2;
  for (int i = 2; i <= 17; i++) {
    for (int j = 1; j < 1 << i; j++) f[i][j] = j;
    solve(1 << i, N, 1, N, i);
  }
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k > 17)
      printf("%d\n", n);
    else
      printf("%lld\n", f[k][n]);
  }
  return 0;
}
