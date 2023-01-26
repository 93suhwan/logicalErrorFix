#include <bits/stdc++.h>
using namespace std;
int check(string s, char c) {
  int ret = 0;
  bool ans = 1;
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i] == s[j]) {
      i++, j--;
    } else if (s[i] == c) {
      i++, ret++;
    } else if (s[j] == c) {
      j--, ret++;
    } else if (s[i] != c && s[j] != c) {
      ans = 0;
      break;
    }
  }
  if (ans)
    return ret;
  else
    return 1e6;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = 1e6;
    for (int i = 'a'; i <= 'z'; i++) {
      ans = min(ans, check(s, i));
    }
    if (ans == 1e6)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
