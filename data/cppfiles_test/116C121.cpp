#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[500005];
long long d[500005][2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) d[i][0] = d[i][1] = 0;
    for (int i = 1; i <= n; i++) {
      d[a[i]][0] = (d[a[i]][0] * 2 + (a[i] ? d[a[i] - 1][0] : 1)) % mod;
      d[a[i]][1] = (d[a[i]][1] * 2) % mod;
      if (a[i] + 2 <= n) d[a[i] + 2][1] = d[a[i] + 2][1] * 2 % mod;
      if (a[i] - 2 >= 0)
        d[a[i]][1] = (d[a[i]][1] + d[a[i] - 2][0]) % mod;
      else if (a[i] == 1)
        d[a[i]][1] = (d[a[i]][1] + 1) % mod;
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + d[i][0] + d[i][1]) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
