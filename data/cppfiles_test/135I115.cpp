#include <bits/stdc++.h>
using namespace std;
int t, n, k, ans, a[100005];
map<int, int> m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    m.clear();
    ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i -= 2) {
      if (!k) break;
      m[i] = m[i + 1];
      k--;
    }
    if (k)
      cout << 0 << "\n";
    else {
      for (int i = 1; i <= n; i++)
        if (!m[a[i]]) ans += a[i];
      cout << ans << "\n";
    }
  }
}
