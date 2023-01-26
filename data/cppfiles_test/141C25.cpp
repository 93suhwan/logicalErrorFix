#include <bits/stdc++.h>
using namespace std;
void solve(long long int testcase) {
  string a, s, ans;
  cin >> a >> s;
  if (s.length() < a.length()) {
    cout << -1 << endl;
    return;
  }
  long long int diff = s.length() - a.length();
  long long int i, j;
  for (i = a.length() - 1, j = s.length() - 1; i >= 0; i--) {
    if (i >= 0 && j < 0) {
      cout << -1 << endl;
      return;
    }
    if ((s[j] - '0') > (a[i] - '0')) {
      long long int ok = (s[j] - '0') - (a[i] - '0');
      ans += (ok + '0');
      j--;
    } else if ((s[j] - '0') < (a[i] - '0')) {
      if (i >= 0 && j < 1) {
        cout << -1 << endl;
        return;
      }
      long long int num = (s[j - 1] - '0') * 10 + (s[j] - '0');
      long long int ok = num - (a[i] - '0');
      if (ok > 9 || num < 10 || num > 18) {
        cout << -1 << endl;
        return;
      }
      ans += (ok + '0');
      j -= 2;
    } else {
      ans += ('0');
      j--;
    }
  }
  while (j >= 0) {
    ans += (s[j]);
    j--;
  }
  while (ans[ans.size() - 1] == '0' && ans.size() > 1) ans.pop_back();
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
signed main() {
  long long int t = 1, i = 1;
  cin >> t;
  while (t--) {
    solve(i);
    i++;
  }
  return 0;
}
