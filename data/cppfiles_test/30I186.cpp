#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 123;
int n, k;
string s;
int check(char c) {
  int ret = 0;
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (s[i] == s[j])
      continue;
    else {
      if (s[i] != c && s[j] != c) return (int)1e9;
      ret++;
      if (s[i] == c) {
        i++;
      } else {
        j--;
      }
    }
  }
  return ret;
}
void solve() {
  cin >> n;
  cin >> s;
  int ans = n + 1;
  int cnt = 0;
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (s[i] == s[j]) {
      continue;
    } else {
      cnt = 1;
      ans = min(ans, check(s[i]));
      ans = min(ans, check(s[j]));
      break;
    }
  }
  if (cnt > 0) {
    if (ans <= n)
      cout << ans << '\n';
    else
      cout << "-1\n";
  } else {
    cout << cnt << '\n';
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
