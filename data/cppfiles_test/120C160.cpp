#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res % p;
}
long long int previouss[200005][31];
void precalculate() {
  long long int N = 2e5 + 5;
  for (long long int i = 1; i < N; i++) {
    for (int j = 0; j <= 30; j++) {
      if (i & (1 << j)) previouss[i][j] = 1;
      previouss[i][j] += previouss[i - 1][j];
    }
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int total = m - n + 1;
  long long int ans = 1e10;
  for (int j = 0; j <= 30; j++) {
    long long int curr = (previouss[m][j] - previouss[n - 1][j]);
    ans = min(ans, total - curr);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  precalculate();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
