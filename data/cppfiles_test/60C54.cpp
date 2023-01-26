#include <bits/stdc++.h>
using namespace std;
long long a[200005];
void solve() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n == 0 || sum * 2 % n == 0) {
    long long ans = 0;
    sum = sum * 2 / n;
    sort(a + 1, a + n + 1);
    long long ll = 1, rr = n;
    while (ll < rr) {
      if (a[ll] + a[rr] == sum && ll < rr) {
        if (a[ll] == a[rr]) {
          ans += (rr - ll + 1) * (rr - ll) / 2;
          break;
        }
        long long suml = 0, sumr = 0;
        for (int i = ll; a[i] == a[ll]; ++i) suml++;
        for (int i = rr; a[i] == a[rr]; --i) sumr++;
        ans += suml * sumr;
        ll += suml;
        rr -= sumr;
      }
      while (a[ll] + a[rr] < sum && ll < rr) ll++;
      while (a[ll] + a[rr] > sum && ll < rr) rr--;
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
