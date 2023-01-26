#include <bits/stdc++.h>
using namespace std;
const int32_t mod = 1000000007;
const int32_t MAXN = 1000005;
long long int bin_exp(long long int n, long long int r) {
  long long int ans = 1;
  while (r >= 1) {
    if (r & 1) ans = (ans * n) % mod;
    n = n * n;
    r /= 2;
  }
  return ans;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int ans = 0;
  for (int i = 0; i < 32; i++) {
    if ((1 << i) & m) {
      ans = (ans + bin_exp(n, i)) % mod;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
