#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MOD1 = 1e9 + 7;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int ans = 0;
  long long int s = 1;
  n--;
  while (s <= n and s <= k) {
    n -= s;
    ans++;
    s *= 2;
  }
  if (n != 0) {
    if (n <= k)
      ans++;
    else
      ans += ceil(n / (k * 1.0));
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
