#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int t;
  cin >> t;
  long long mod = 1e9 + 7;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    long long multiplier = 1;
    for (int i = 0; i <= 30; i++) {
      if (k & 1 << i) ans = (ans + multiplier) % mod;
      multiplier = (multiplier * n) % mod;
    }
    cout << ans << endl;
  }
}
