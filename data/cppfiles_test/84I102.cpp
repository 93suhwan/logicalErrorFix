#include <bits/stdc++.h>
using namespace std;
const long long N = 5100;
long long te, n, k, phi[N], a[N], d[20][N];
long long c(long long l, long long r) {
  if (l > r) return long long(2e12);
  long long ans = 0;
  for (long long i = l; i <= r; i++) ans += a[r / i];
  return ans;
}
void dnc(long long lvl, long long l, long long r, long long x, long long y) {
  if (l > r) return;
  long long mid = (l + r) / 2, opt = x, calc = c(min(mid, y) + 1, mid), cur;
  d[lvl][mid] = long long(2e12);
  for (long long j = min(mid, y); j >= x; j--) {
    if (calc == long long(2e12))
      calc = a[mid / j];
    else
      calc += a[mid / j];
    cur = d[lvl - 1][j - 1] + calc;
    if (d[lvl][mid] > cur) d[lvl][mid] = cur, opt = j;
  }
  dnc(lvl, l, mid - 1, x, opt);
  dnc(lvl, mid + 1, r, opt, y);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = 1; i < N; i++) phi[i] = i;
  for (long long i = 2; i < N; i++)
    if (phi[i] == i)
      for (long long j = i; j < N; j += i) phi[j] -= phi[j] / i;
  for (long long i = 1; i < N; i++) a[i] = a[i - 1] + phi[i];
  for (long long i = 1; i < N; i++) d[1][i] = c(1, i);
  for (long long i = 1; i <= 17; i++) d[i][0] = long long(2e12);
  for (long long i = 2; i <= 17; i++) dnc(i, 1, N - 1, 1, N - 1);
  cin >> te;
  for (; te--;) {
    cin >> n >> k;
    if (k > 17)
      cout << n << "\n";
    else
      cout << d[k][n] << "\n";
  }
}
