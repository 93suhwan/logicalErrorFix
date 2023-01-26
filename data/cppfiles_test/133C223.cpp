#include <bits/stdc++.h>
using namespace std;
int solve() {
  long long int n;
  cin >> n;
  long long int no = n - 2;
  string ans = "";
  vector<string> s(no);
  for (long long int i = 0; i < no; i++) {
    cin >> s[i];
  }
  if (n == 3) {
    ans += s[0];
    ans += s[0][1];
    cout << ans << "\n";
    return 0;
  }
  for (long long int i = 0; i < no - 1; i++) {
    if (i == 0) {
      ans += s[i][0];
    }
    if (s[i][1] == s[i + 1][0]) {
      ans += s[i][1];
    } else {
      ans += s[i][1];
      ans += s[i + 1][0];
    }
    if (i == no - 2) {
      ans += s[i + 1][1];
    }
  }
  if (ans.length() == n - 1) {
    ans += ans[ans.length() - 1];
  }
  cout << ans << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
