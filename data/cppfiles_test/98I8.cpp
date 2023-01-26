#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == 'a' and s[i + 1] == 'b') {
        cout << i + 1 << " " << i + 2 << "\n";
        goto l;
      }
    }
    cout << -1 << " " << -1 << "\n";
  l:;
  }
  return 0;
}
