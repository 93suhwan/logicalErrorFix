#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, n, m, j, k;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    long long int ans = 0;
    for (i = 0; i < n - 1; i++) {
      int d = s[i] - '0';
      if (d > 0) {
        ans++;
        ans += d;
      }
    }
    ans += s[n - 1] - '0';
    cout << ans << endl;
  }
}
