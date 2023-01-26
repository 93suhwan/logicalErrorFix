#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 1;
const long long INF = 1e9 + 7;
const long long inf = 1e18;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    k--;
    k--;
    long long comp = n * (n - 1) / 2;
    if (m < n - 1) {
      cout << "NO" << '\n';
    } else if (m > comp) {
      cout << "NO" << '\n';
    } else if (k == 1 && m == comp) {
      cout << "YES" << '\n';
    } else if (k > 1) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
