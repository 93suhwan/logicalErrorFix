#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long p10[10] = {};
  p10[0] = 1;
  for (int i = 1; i <= 9; ++i) p10[i] = p10[i - 1] * 10;
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    k++;
    long long a[n], ans = 0;
    for (int i = 0; i <= n - 1; ++i) cin >> a[i];
    for (int i = 1; i <= n - 1; ++i) {
      long long take = min(k, p10[a[i] - a[i - 1]] - 1);
      ans += p10[a[i - 1]] * take;
      k -= take;
    }
    ans += p10[a[n - 1]] * k;
    cout << ans << "\n";
  }
  return 0;
}
