#include <bits/stdc++.h>
using namespace std;
int T, cnt[26];
string t, ans, tmp, s, ss, sss;
int main() {
  cin >> T;
  while (T--) {
    int x = 0, anslen = 0;
    ans = tmp;
    cin >> t;
    for (int i = t.size() - 1; i >= 0; i--)
      if ((++cnt[t[i] - 'a']) == 1) ans += t[i];
    x = ans.size();
    for (int i = 0; i <= (x - 1) / 2; i++) swap(ans[i], ans[x - i - 1]);
    for (int i = 0; i < x; i++) anslen += cnt[ans[i] - 'a'] / (i + 1);
    s = ss = t.substr(0, anslen);
    for (int i = 0; i < x; i++) {
      sss = tmp;
      for (int j = 0; j < s.size(); j++)
        if (s[j] != ans[i]) sss += s[j];
      s = sss;
      ss += s;
    }
    for (int i = 0; i < 26; i++) cnt[i] = 0;
    if (ss != t)
      cout << -1 << endl;
    else
      cout << t.substr(0, anslen) << " " << ans << endl;
  }
  return 0;
}
