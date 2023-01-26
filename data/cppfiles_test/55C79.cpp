#include <bits/stdc++.h>
using namespace std;
namespace std {}
long long t, n, m;
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  long long mod = 1e9 + 7;
  long long ans = 6;
  long long k = 16;
  n -= 1;
  while (n--) {
    ans = (ans * k) % mod;
    k = (k * k) % mod;
  }
  cout << ans;
}
