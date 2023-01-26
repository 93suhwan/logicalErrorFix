#include <bits/stdc++.h>
const long long mod = 1000000007;
const long long AM = 2e5 + 5;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long i = 1, ans = 0;
    while (i < k && i < n) i *= 2, ans++;
    if (i > n) {
      cout << ans << '\n';
      continue;
    }
    n -= i;
    ans += n / k;
    if (n % k != 0) ans++;
    cout << ans << '\n';
  }
}
