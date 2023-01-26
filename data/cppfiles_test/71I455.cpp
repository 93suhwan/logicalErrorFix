#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long qpow(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long ans;
int n, k;
int a[3];
void dfs(int m, int x, int y, long long s) {
  if (m == 10 || s > ans) return;
  if (a[1] > 0 && a[2] > 0 && s >= n) {
    ans = min(ans, s);
  }
  a[1]++;
  dfs(m + 1, x, y, s * 10 + x);
  a[1]--;
  a[2]++;
  dfs(m + 1, x, y, s * 10 + y);
  a[2]--;
}
void solve() {
  cin >> n >> k;
  ans = 1e13;
  for (int i = 1; i <= 9; i++) {
    for (long long j = i; j <= 1e13; j = j * 10 + i) {
      if (j >= n) {
        ans = min(ans, j);
      }
    }
  }
  if (k == 2) {
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        if (i == j) continue;
        a[1] = a[2] = 0;
        dfs(0, i, j, 0);
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int Case;
  cin >> Case;
  while (Case--) {
    solve();
  }
  return 0;
}
