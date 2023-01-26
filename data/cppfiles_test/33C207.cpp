#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long op[N];
int f[N][20], dp[N][20];
string ss;
int n;
long long query(int l, int r) {
  int s = log(r - l + 1);
  return 1ll * max(f[l][s], f[r - (1 << s) + 1][s]) *
         min(dp[l][s], dp[r - (1 << s) + 1][s]);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> op[i];
    long long ans = -0x3f3f3f3f3f3f3f3f;
    for (int i = 2; i <= n; i++) ans = max(ans, op[i] * op[i - 1]);
    cout << ans << "\n";
  }
  return 0;
}
