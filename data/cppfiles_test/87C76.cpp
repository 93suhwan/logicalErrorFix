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
        res += a - i;
        n += a - i;
        i += a - i;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
