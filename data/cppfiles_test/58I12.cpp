#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  short int t, n, i;
  cin >> t;
  string x, y;
  while (t--) {
    cin >> n;
    cin >> x;
    cin >> y;
    bool b = 1;
    for (i = 1; i < n; i++) {
      if ((x[i - 1] + x[i] + y[i - 1] + y[i] - 192) >= 3) {
        b = 0;
        break;
      }
    }
    cout << ((b == 1) ? ("YES\n") : ("NO\n"));
  }
  return 0;
}
