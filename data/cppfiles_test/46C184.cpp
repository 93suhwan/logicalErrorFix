#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, d, o = 0, k, ans = 0, so = 0;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n - 1; i += 2) {
    d = min(a[i], a[i + 1]);
    o = 0;
    ans += d;
    so = a[i] - d;
    if (a[i] >= a[i + 1]) {
      for (k = i + 2; k < n - 1; k += 2) {
        o += a[k];
        if (o > a[k + 1]) {
          o -= a[k + 1];
          continue;
        } else if (so + o < a[k + 1]) {
          ans += so + 1;
          break;
        } else {
          ans++;
          d = a[k + 1] - o;
          ans += d;
          so -= d;
          o = 0;
        }
      }
    }
  }
  cout << ans << "\n";
}
