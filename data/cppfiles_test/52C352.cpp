#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long temp = n;
  long long po = 1;
  long long ans = 0;
  for (int bit = 0; bit < 31; bit++) {
    if ((k >> bit) & 1) {
      ans = ans + po;
      ans %= MOD;
    }
    po *= n;
    po %= MOD;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
