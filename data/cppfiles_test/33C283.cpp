#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i, j, k, l, r, m;
  cin >> n;
  vector<long long int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  ;
  auto itr = max_element(a.begin(), a.end());
  long long int di = distance(a.begin(), itr);
  long long int left = -1;
  long long int ans = 0;
  for (i = 1; i < n; i++) {
    ans = max(ans, a[i] * a[i - 1]);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, n, m;
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
