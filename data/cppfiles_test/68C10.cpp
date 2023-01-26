#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;
void solve() {
  long long k;
  cin >> k;
  for (long long i = 1; i * i <= INF; i++) {
    if (k == i * i) {
      cout << i << " " << 1 << "\n";
      return;
    }
    if (k > i * i && k < (i + 1) * (i + 1)) {
      i++;
      long long r, c;
      if ((i * i) - i + 1 >= k) {
        r = i - ((i * i) - i + 1 - k);
        c = i;
      } else {
        r = i;
        c = (i * i) - k + 1;
      }
      cout << r << " " << c << "\n";
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
  return 0;
}
