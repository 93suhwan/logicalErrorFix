#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 100;
int pre[max_n], suff[max_n];
int a[max_n], b[max_n];
int n;
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n + 10; ++i) pre[i] = suff[i] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = n; i >= 1; --i) suff[i] = suff[i + 1] + a[i];
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + b[i];
    int ans = pre[n];
    for (int i = 1; i <= n; ++i) ans = min(ans, max(pre[i - 1], suff[i + 1]));
    cout << ans << endl;
  }
}
