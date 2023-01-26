#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 10;
void test_case() {
  long long n;
  cin >> n;
  vector<int> a(n);
  long double suff = 0, pre = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    suff += a[i];
  }
  sort(a.begin(), a.end());
  long double ans = a[n - 1] + (suff - a[n - 1]) / (n - 1);
  cout << fixed << setprecision(6) << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) test_case();
  return 0;
}
