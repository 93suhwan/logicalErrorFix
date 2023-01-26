#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int tc;
  cin >> tc;
  while (tc--) {
    long long int n;
    cin >> n;
    string s[n - 2];
    for (long long int i = 0; i < n - 2; i++) cin >> s[i];
    string ans;
    ans += s[0][0];
    for (long long int i = 1; i < n - 2; i++) {
      if (s[i - 1][1] == s[i][0]) {
        ans += s[i][0];
      } else {
        ans += s[i - 1][1];
        ans += s[i][0];
      }
    }
    ans += s[n - 3][1];
    if (ans.size() < n) ans += s[0][0];
    cout << ans << endl;
  }
  return 0;
}
