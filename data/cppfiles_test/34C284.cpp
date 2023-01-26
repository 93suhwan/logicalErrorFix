#include <bits/stdc++.h>
using namespace std;
int T;
int a[100005];
int main() {
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    long long ans = -9999999;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 1; i--) {
      if (ans < 1ll * i * (i - 1) - k * a[i])
        for (int j = i - 1; j >= 1; j--)
          ans = max(ans, 1ll * i * j - k * (a[i] | a[j]));
    }
    cout << ans << '\n';
  }
  return 0;
}
