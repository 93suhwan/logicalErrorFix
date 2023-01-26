#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const long long int INF = 1e18;
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  for (long long int i = 1; i <= b; i++) {
    ans *= a;
  }
  return ans;
}
void solve(void) {
  long long int n, k;
  cin >> n >> k;
  long long int x = floor(log2(k));
  long long int ans = 0;
  while (k) {
    k -= power(2, x);
    ans = (ans + power(n, x)) % MOD;
    x = floor(log2(k));
  }
  cout << ans;
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
