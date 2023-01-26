#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000005;
const long long INF = 1e18;
int a[MAXN], b[MAXN];
int suba[MAXN], subb[MAXN];
inline void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) a[i] = b[i] = suba[i] = subb[i] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] >= m) {
      suba[i] = m;
      a[i] -= suba[i];
    } else {
      suba[i] = a[i], subb[i] = (m - a[i]);
      a[i] -= suba[i], b[i] -= subb[i];
    }
  }
  long long sumA = 0, sumB = 0;
  for (int i = 1; i <= n; i++) {
    sumA += a[i];
    sumB += b[i];
  }
  if (sumA >= sumB) {
    cout << abs(sumA - sumB) << "\n";
    return;
  }
  long long tmp = (sumB - sumA) / 2;
  for (int i = 1; i <= n; i++) {
    int t = min(suba[i], b[i]);
    if (tmp >= t) {
      a[i] += t, b[i] -= t;
      suba[i] -= t, subb[i] += t;
      tmp -= t;
    } else {
      a[i] += tmp, b[i] -= tmp;
      suba[i] -= tmp, subb[i] += tmp;
      tmp = 0;
      break;
    }
  }
  sumA = 0, sumB = 0;
  for (int i = 1; i <= n; i++) sumA += a[i], sumB += b[i];
  cout << abs(sumA - sumB) << "\n";
  for (int i = 1; i <= n; i++) cout << suba[i] << " " << subb[i] << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
