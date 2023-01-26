#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  long long rem = k + 1;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; rem > 0 and i < n - 1; i++) {
    long long maxi = ceil(pow(10, (a[i + 1] - a[i])));
    long long take = min(1ll * rem, maxi - 1);
    cerr << take << '\n';
    rem -= take;
    ans += 1ll * take * pow(10, a[i]);
    cerr << take << " " << ans << '\n';
  }
  if (rem) {
    ans += rem * pow(10, a[n - 1]);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cerr.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
