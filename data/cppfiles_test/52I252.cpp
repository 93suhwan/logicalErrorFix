#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const long long int INF = 1e18;
void solve(void) {
  long long int n, k;
  cin >> n >> k;
  long long int x = log2(k);
  long long int ans = 0;
  while (k) {
    k -= pow(2, x);
    ans += (long long int)pow(n, x) % MOD;
    x = log2(k);
  }
  cout << ans % MOD;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
