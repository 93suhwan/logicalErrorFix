#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 5;
const int M = 3e4 + 5;
const long long INF = (long long)(1e18);
const int inf = 2e9;
const long long MOD = 1000000007LL;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2) {
    if (k < m / 2) {
      cout << "NO\n";
      return;
    }
    n--;
    k -= m / 2;
  }
  if (m % 2) m--;
  if (k % 2 || 2 * k > n * m) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
