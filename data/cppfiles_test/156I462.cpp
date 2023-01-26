#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n);
  long long int sum = 0;
  for (int(i) = (0); (i) < (n); ++(i)) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum <= k) {
    cout << 0 << "\n";
    return;
  }
  if (n == 1) {
    cout << a[0] - k << "\n";
    return;
  }
  sort((a).begin(), (a).end());
  long long int mn = a[0];
  long long int ans = 1 << 30;
  long long int mcnt = 0;
  while (mn > -a[n - 1]) {
    long long int cnt = mcnt, curr = sum - (a[0] - mn);
    for (long long int i = n - 1; i >= 1; --i) {
      curr -= (a[i] - mn);
      cnt += 1;
      if (curr <= k) {
        if (cnt > ans) {
          break;
        }
        ans = min(ans, cnt);
        break;
      }
    }
    mn--;
    mcnt += 1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
