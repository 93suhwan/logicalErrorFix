#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    m++;
    int ans = 0;
    bool check = false;
    for (int i = 30; i >= 0; --i) {
      if (check) {
        if (((m >> i) & 1) == 1) ans += (1 << i);
        continue;
      }
      if (((n >> i) & 1) == ((m >> i) & 1)) continue;
      if (((n >> i) & 1) == 1)
        check = true;
      else {
        ans += (1 << i);
      }
    }
    cout << ans << endl;
  }
}
