#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long f[N], M = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, n, m, l, r;
  f[3] = 3;
  for (i = 4; i < N; i++) f[i] = (f[i - 1] * i) % M;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1)
      cout << "1\n";
    else
      cout << f[2 * n] << "\n";
  }
  return 0;
}
