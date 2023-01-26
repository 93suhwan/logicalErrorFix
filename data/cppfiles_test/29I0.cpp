#include <bits/stdc++.h>
const int MAXN = 3e5 + 15;
using namespace std;
long long fwt[MAXN][3];
long long A[MAXN];
void update(int k, int x, long long val) {
  while (x <= MAXN) {
    fwt[x][k] += val;
    x += (x & (-x));
  }
}
long long rsum(int k, int x) {
  long long su = 0;
  while (x >= 1) {
    su += fwt[x][k];
    x -= (x & (-x));
  }
  return su;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i + 1];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long x = A[i];
    if (x == 1) {
      update(0, x, 1);
      update(1, x, x);
    } else {
      for (int k = 0; k < MAXN; k += x) {
        int l = k + 1;
        int r = min(MAXN + 0LL, k + x - 1);
        ans += rsum(1, r) - rsum(1, l - 1) - (rsum(0, r) - rsum(0, l - 1)) * x;
      }
      update(0, x, 1);
      update(1, x, x);
    }
    ans += x * (i - 1) - (rsum(2, x) - rsum(2, x - 1));
    for (int k = 0; k * x < MAXN; k++) {
      int l = max(k * x, 1LL);
      int r = min(k * x + x - 1, 0LL + MAXN);
      update(2, r + 1, -k * x);
      update(2, l, k * x);
    }
    cout << ans << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
