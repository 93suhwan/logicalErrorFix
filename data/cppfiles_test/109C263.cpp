#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int_fast64_t t;
  cin >> t;
  while (t--) {
    int_fast64_t n;
    cin >> n;
    string s;
    cin >> s;
    int_fast64_t sum = 0;
    for (int_fast64_t i = 0; i < n; i++) {
      if ((s[i] - '0') != 0) {
        sum += s[i] - '0';
        sum += (i != (n - 1));
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
