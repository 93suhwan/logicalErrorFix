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
    string bit;
    while (k != 0) {
      bit += (k % 2 == 0 ? '0' : '1');
      k /= 2;
    }
    for (int i = 0; i < bit.size(); i++) {
      if (bit[i] == '1') {
        ans = (ans + (long long)pow(n, i)) % MOD;
      }
      ans %= MOD;
    }
    cout << ans << endl;
  }
}
