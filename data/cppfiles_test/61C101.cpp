#include <bits/stdc++.h>
using namespace std;
long long a[200005];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), ca(n + 1), cb(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    ca[a[i]]++;
    cb[b[i]]++;
  }
  long long ans = n * 1LL * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; ++i) ans -= (ca[a[i]] - 1) * 1LL * (cb[b[i]] - 1);
  cout << ans << '\n';
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
