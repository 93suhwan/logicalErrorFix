#include <bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9 + 7);
const int N = 200010;
const int inf = (int)(1e9);
long long cnt[21][N];
void solve() {
  long long l, r;
  cin >> l >> r;
  long long ans = INT_MIN;
  for (long long i = 1; i <= 20; i++) {
    ans = max(ans, cnt[i][r] - cnt[i][l - 1]);
  }
  cout << r - l + 1 - ans << "\n";
}
signed main() {
  long long fact = 2;
  long long rem = 1;
  for (long long i = 1; i <= 20; i++) {
    cnt[i][0] = 0;
    for (long long j = 1; j < N; j++) {
      if (j % fact >= rem) {
        cnt[i][j] = 1;
      }
      cnt[i][j] += cnt[i][j - 1];
    }
    fact *= 2;
    rem *= 2;
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
