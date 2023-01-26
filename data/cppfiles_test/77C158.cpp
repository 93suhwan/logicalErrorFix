#include <bits/stdc++.h>
using namespace std;
int n, m;
void solve() {
  cin >> n >> m;
  vector<long long> f(n + 1, 0);
  f[1] = 1;
  long long cursum = 0;
  for (int i = 2; i <= n; i++) {
    cursum += f[i - 1] + f[1];
    cursum %= m;
    f[i] += cursum;
    f[i] %= m;
    cursum = f[i];
    for (int j = 2 * i; j <= n; j += i) {
      f[j] += (f[i] - f[i - 1]);
      f[j] %= m;
    }
  }
  cout << (f[n] + m) % m << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(10);
  int t = 1;
  while (t--) solve();
}
