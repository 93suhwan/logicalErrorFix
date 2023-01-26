#include <bits/stdc++.h>
const long long M = 1e9 + 7;
using namespace std;
long long dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void test_cases() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<long long>());
  long long ans = 0;
  for (long long i = k; i < 2 * k; i++) {
    ans += a[i] / a[i - k];
  }
  for (long long i = 2 * k; i < n; i++) {
    ans += a[i];
  }
  cout << ans << '\n';
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    test_cases();
  }
}
