#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int t;
int n, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long ans = 0;
    long long power = 1;
    while (k != 0) {
      long long d = k % 2;
      k /= 2;
      ans += (d * power);
      ans %= MOD;
      power *= n;
      power %= MOD;
    }
    cout << ans << endl;
  }
}
