#include <bits/stdc++.h>
using namespace std;
const long long NMX = 432000, oo = 0x3C3C3C3C3C3C3C3C, Bs = 1000000007;
long long q, n, m, k, d;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> q;
  while (q--) {
    cin >> n >> m >> k;
    k -= 2;
    d = n * (n - 1) / 2;
    cout << (m == d && k >= 1 || m < d && m >= n - 1 && k > 1 ? "YES\n"
                                                              : "NO\n");
  }
  return 0;
}
