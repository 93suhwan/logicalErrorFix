#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    ar[i] = pow(10, ar[i]);
  }
  sort(ar, ar + n);
  if (n == 1) {
    cout << k + 1 << endl;
    return;
  }
  if (ar[1] > k) {
    cout << k + 1 << endl;
    return;
  }
  long long ans = 9;
  k -= 8;
  for (int i = 1; i < n; i++) {
    if (i + 1 < n && k * ar[i] >= ar[i + 1]) {
      long long kk = ar[i + 1] - ar[i];
      k -= kk / ar[i];
      ans += kk;
    } else {
      ans += k * ar[i];
      break;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
