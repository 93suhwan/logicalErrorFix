#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int m) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (n & 1) {
      long long int ans = power(2, n - 1, 1000000007);
      ans += 1;
      ans %= 1000000007;
      ans = power(ans, k, 1000000007);
      cout << ans << endl;
    } else {
      long long int ans = power(2, n - 1, 1000000007);
      ans -= 1;
      ans += 1000000007;
      ans %= 1000000007;
      ans = power(ans, k, 1000000007);
      long long int ans2 = power(2, n, 1000000007);
      ans2 = power(ans2, k, 1000000007);
      ans2 -= 1;
      ans2 += 1000000007;
      ans2 %= 1000000007;
      long long int den = power(2, n, 1000000007);
      den -= 1;
      den += 1000000007;
      den %= 1000000007;
      den = power(den, 1000000007 - 2, 1000000007);
      ans2 *= den;
      ans2 %= 1000000007;
      ans += ans2;
      ans %= 1000000007;
      cout << ans << endl;
    }
  }
}
