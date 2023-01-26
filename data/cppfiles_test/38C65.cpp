#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k, n, m, ans, val, tot, res, t, temp, first, a, b, c, a1, b1,
      c1;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n & 1) ++n;
    n = max(n, 6LL);
    n = (n * 5) / 2;
    cout << n << "\n";
  }
  return 0;
}
