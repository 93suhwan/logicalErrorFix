#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, ans = 0, i;
    cin >> n >> m;
    m++;
    for (i = 35; i >= 0; i--) {
      if ((n >> i) == (m >> i)) {
        continue;
      }
      if ((m >> i) > 0) {
        n = n | (1 << i);
        ans = ans | (1 << i);
      }
      if (n >= m) {
        break;
      }
    }
    cout << ans << '\n';
  }
}
