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
  if (k < ar[1] - 1) {
    cout << k + 1 << endl;
    return;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i + 1 < n) {
      long long kk = ar[i + 1] / ar[i];
      kk--;
      long long use = min(kk, k);
      if (i == 0) use--;
      k -= use;
      ans += ar[i] * use;
      if (k == 0) break;
    } else {
      ans += ar[i] * k;
      break;
    }
  }
  cout << ans + 1 << endl;
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
