#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
const int N = 4e6 + 10;
int d[N], ans[N], sum[N];
void solve() {
  int n, m;
  cin >> n >> m;
  ans[1] = 1;
  for (int i = 2; i <= n; i++) d[i] = 1;
  sum[1] = 1;
  for (int i = 2; i <= n; i++) {
    d[i] += d[i - 1];
    d[i] %= m;
    ans[i] = (d[i] + sum[i - 1]) % m;
    for (int j = i + i; j <= n; j += i) {
      d[j] -= ans[i - 1];
      d[j] %= m;
      d[j] += ans[i];
      d[j] %= m;
      if (d[j] < 0) d[j] += m;
    }
    sum[i] = (sum[i - 1] + ans[i]) % m;
  }
  cout << ans[n] << "\n";
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int tc = 1;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
