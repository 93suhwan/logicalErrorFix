#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const long long N = 1e6 + 50;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) {
    long long n, k;
    cin >> n >> k;
    long long a[n + 10];
    long long ans = -oo;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i < min(n - 1, 150LL); i++) {
      for (int j = i + 1; j <= min(n, 151LL); j++) {
        ans = max(i * j - (k * (a[i] | a[j])), ans);
      }
    }
    for (int i = n; i > max(0LL, n - 150LL); i--) {
      for (int j = i - 1; j > max(0LL, n - 151LL); j--) {
        ans = max(i * j - (k * (a[i] | a[j])), ans);
      }
    }
    ans = max(ans, n * (n - 1) - (k * (a[n - 1] | a[n])));
    cout << ans << '\n';
  }
  return 0;
}
