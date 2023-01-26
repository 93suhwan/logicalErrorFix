#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
using namespace std;
const int maxn = 110;
long long a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long h;
    int n;
    cin >> n >> h;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long l = 1, r = h, ans = h;
    while (l < r) {
      long long md = (l + r) / 2, sum = 0;
      for (int i = 1; i < n; i++) sum += min(md, a[i] - a[i - 1]);
      sum += md;
      if (h <= sum)
        ans = r = md;
      else
        l = md + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
