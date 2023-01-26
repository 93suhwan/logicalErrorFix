#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[4000005], sum[4000005];
void solve() {
  cin >> n >> m;
  f[n] = 1;
  sum[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    f[i] = (f[i] + sum[i + 1]) % m;
    for (int j = 2; j <= n / i; j++) {
      int l = i * j, r = min(n, (i + 1) * j - 1);
      int u = (sum[l] - sum[r + 1] + m) % m;
      f[i] = (f[i] + u) % m;
    }
    sum[i] = (sum[i + 1] + f[i]) % m;
  }
  cout << f[1];
}
int main() {
  ios::sync_with_stdio(false);
  solve();
}
