#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  long long ans = 0;
  string arr = "";
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      arr[i] = '2';
    } else {
      arr[i] = s1[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == '2') {
      ans += 2;
    } else {
      if (i <= n - 2 && arr[i + 1] != arr[i] && arr[i] != '2') {
        ans += 2;
        i++;
      } else {
        if (arr[i] == '0') {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
