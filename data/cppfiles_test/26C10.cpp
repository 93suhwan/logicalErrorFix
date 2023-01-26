#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b /= 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int ans = 1;
    for (int i = 3; i <= n + n; i++) {
      ans *= i;
      ans %= MOD;
    }
    cout << ans << "\n";
  }
  return 0;
}
