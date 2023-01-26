#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t, i, j, x, a, y, m, c, ans, sum, r, p, q, k, z, d, n, l, b;
  t = 1;
  string s, s1;
  cin >> t;
  while (t--) {
    cin >> n;
    n *= 2;
    p = 1;
    for (int i = 3; i <= n; i++) {
      (p *= i) %= 1000000007;
    }
    cout << p << "\n";
  }
}
