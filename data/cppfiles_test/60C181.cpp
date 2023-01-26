#include <bits/stdc++.h>
using namespace std;
const long long gebura = 2e6 + 100;
const long long mod = 1e9 + 7;
long long hod[gebura];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
      cin >> hod[i];
      if (ans == INT_MAX) {
        ans = hod[i];
      } else
        ans = ans & hod[i];
    }
    cout << ans << endl;
  }
  return 0;
}
