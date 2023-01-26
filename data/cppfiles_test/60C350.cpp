#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  int i;
  vector<long long int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (i = 31; i >= 0; i--) {
    int f = 0;
    for (int j = 0; j < n; j++) {
      if (((a[j] >> i) & 1) == 0) f = 1;
    }
    if (f == 0) ans = ans + pow(2, i);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
}
