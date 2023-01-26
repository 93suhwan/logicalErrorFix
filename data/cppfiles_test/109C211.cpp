#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int Z;
  cin >> Z;
  while (Z--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      char x = s[i];
      if (x != '0') ans += ((i == n - 1) ? 0 : 1) + (x - '0');
    }
    cout << ans << '\n';
  }
  return 0;
}
