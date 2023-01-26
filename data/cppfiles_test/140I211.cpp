#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sq = sqrt(n);
    int pw = cbrt(n);
    int ans = sq + pw - sqrt(cbrt(n)) + 1;
    if (n == 1)
      cout << 1 << endl;
    else
      cout << ans << endl;
  }
}
