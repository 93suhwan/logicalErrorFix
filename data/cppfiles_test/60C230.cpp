#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int ar[n];
  for (int(i) = 0; (i) < n; i++) cin >> ar[i];
  long long sum = accumulate(ar, ar + n, 0LL);
  if ((2 * sum) % n) {
    cout << "0\n";
    return;
  }
  int need = 2 * sum / n;
  map<int, int> mp;
  long long ans = 0;
  for (int(i) = 0; (i) < n; i++) {
    ans += mp[need - ar[i]];
    mp[ar[i]]++;
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
