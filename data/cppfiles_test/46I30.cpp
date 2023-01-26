#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, l, k, o, c, ans = 0;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 1; i < n; i += 2) {
    k = i - 1, o = 0, c = 0;
    while (k >= 0) {
      o += a[k];
      c += a[k + 1];
      if (o <= c) {
        ans += min(a[k], a[i]);
      } else
        break;
      k -= 2;
    }
  }
  cout << ans << "\n";
}
