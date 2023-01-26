#include <bits/stdc++.h>
using namespace std;
char en = '\n';
void fileIO() {}
const long long MOD = 1e12;
long long first, n, m, k;
void solve() {
  cin >> n >> m >> k;
  first = 0;
  if (n % 2 && m % 2 == 0) {
    if ((2 * k) % m == 0 && ((2 * k) / m) % 2)
      first = 1;
    else if (2 * k > m) {
      k -= (m / 2);
      for (long long i = 0; i <= n - 1; i += 2) {
        for (long long j = 1; j < m / 2 + 1; j++)
          if (i * j == k) first = 1;
      }
    }
  } else if (n % 2 == 0) {
    for (long long i = 0; i <= n; i += 2) {
      for (long long j = 1; j < m / 2 + 1; j++)
        if (i * j == k) first = 1;
    }
  }
  if (first)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fileIO();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << en;
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
