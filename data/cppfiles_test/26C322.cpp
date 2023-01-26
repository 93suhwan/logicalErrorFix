#include <bits/stdc++.h>
using namespace std;
int32_t mod = 1000000007;
void solveCase() {
  long long n = 0;
  cin >> n;
  long long ans = 1, p = 2 * n;
  while (p > 2) {
    ans *= p;
    ans %= mod;
    p--;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solveCase();
}
