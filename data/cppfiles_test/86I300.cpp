#include <bits/stdc++.h>
using namespace std;
long long Q, n, a[2][100005], ans, vis[100005];
char s[2][100005];
signed main() {
  cin >> Q;
  while (Q--) {
    scanf("%lld%s%s", &n, s[0] + 1, s[1] + 1);
    for (long long i = 0; i <= n + 1; i++) vis[i] = 0;
    for (long long i = 1; i <= n; i++)
      a[0][i] = s[0][i] - '0', a[1][i] = s[1][i] - '0';
    ans = 0;
    a[0][0] = a[1][0] = 1, vis[0] = 1;
    for (long long i = 1; i <= n; i++) {
      if ((a[0][i] ^ a[1][i]) == 1) {
        ans += 2;
        continue;
      }
      if (a[0][i] == 0 && a[1][i] == 0)
        ans++;
      else if (a[0][i] == 1 && a[1][i] == 1) {
        if (!vis[i - 1] && a[0][i - 1] == 0 && a[1][i - 1] == 0)
          ans++, vis[i - 1] = 1;
        else if (!vis[i + 1] && a[0][i + 1] == 0 && a[1][i + 1] == 0)
          ans++, vis[i + 1] = 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
