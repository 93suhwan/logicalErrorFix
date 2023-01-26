#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, d, c, o, k, ans = 0;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 1; i < n; i += 2) {
    ans += min(a[i - 1], a[i]);
    k = i - 3;
    d = min(a[i - 1], a[i]);
    c = a[i] - d;
    o = a[i - 1] - d;
    if (o <= c) {
      while (k >= 0) {
        if (a[k + 1] <= a[k])
          ans++;
        else
          break;
        d = min(a[k], a[k + 1]);
        o += a[k] - d;
        c += a[k + 1] - d;
        if (o > c) {
          ans += c;
          break;
        } else {
          ans += o;
          o = 0;
          c = c - o;
        }
        k -= 2;
      }
    }
  }
  cout << ans << "\n";
}
