#include <bits/stdc++.h>
using namespace std;
long long int p1(long long int x, long long int y) {
  long long int ans = 1;
  while (y) {
    if (y & 1ll) {
      ans = (ans * x) % 1000000007;
    }
    y /= 2;
    x = (x * x) % 1000000007;
  }
  return ans;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int ans = 0;
  for (long long int i = 0; i <= 32; i++) {
    if ((1ll << i) & k) {
      long long int tmp = p1(n, i) % 1000000007;
      ans = (ans + tmp) % 1000000007;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
