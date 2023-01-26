#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (long long int k = 1; k <= t; k++) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] != '0') {
        ans = ans + (s[i] - '0');
        if (i != n - 1) ans++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
