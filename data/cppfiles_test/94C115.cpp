#include <bits/stdc++.h>
using namespace std;
const int int_inf = 0x3f3f3f3f;
const long long int ll_inf = 0x3f3f3f3f3f3f3f3f;
const int max_n = 1e5 + 5;
int tt[15];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  tt[0] = 1;
  for (int i = 1; i < 10; i++) tt[i] = tt[i - 1] * 10;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    k++;
    long long int ans = 0;
    for (int i = 0; k && i < n - 1; i++) {
      int d = a[i + 1] - a[i];
      d = tt[d] - 1;
      if (d >= k) {
        ans += 1ll * k * tt[a[i]];
        k = 0;
      } else {
        ans += 1ll * d * tt[a[i]];
        k -= d;
      }
    }
    if (k) {
      ans += 1ll * k * tt[a[n - 1]];
    }
    cout << ans << '\n';
  }
  return 0;
}
