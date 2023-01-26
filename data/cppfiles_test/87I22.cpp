#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, a, last, res;
  cin >> t;
  while (t--) {
    last = res = 0;
    cin >> n;
    for (long long int i = 1; i < n + 1; i++) {
      cin >> a;
      if (a > i) {
        last = res;
        res += a - i;
      }
    }
    cout << res - last << "\n";
  }
  return 0;
}
