#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int N = 2e5 + 5;
long long cnt[N][32];
bool check(int n, int k) { return n & (1 << k); }
void init() {
  memset(cnt, 0xf, sizeof(cnt));
  for (int i = 0; i < 32; i++) cnt[0][i] = 0;
  for (int i = 0; i < 32; i++) {
    long long p = 0;
    for (int j = 1; j < N; j++) {
      if (!check(j, i)) p++;
      cnt[j][i] = min(cnt[j][i], p);
    }
  }
}
void solve() {
  long long ans = INT_MAX;
  int l, r;
  cin >> l >> r;
  for (int i = 0; i < 32; i++) ans = min(ans, cnt[r][i] - cnt[l - 1][i]);
  cout << ans << nl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  init();
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
