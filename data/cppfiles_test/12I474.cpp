#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
void slove() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long h = 0.;
  if (n % 2 == 1) {
    h = m / 2;
  }
  if ((k - h) % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) slove();
  return 0;
}
