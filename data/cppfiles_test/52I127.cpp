#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e9;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int p = 0;
  long long int ans = 0;
  while (k > 0) {
    if (k & 1) {
      ans += pow(n, p);
    }
    p++;
    k = k >> 1;
  }
  cout << ans % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
    cout << "\n";
  }
}
