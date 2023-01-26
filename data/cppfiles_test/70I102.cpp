#include <bits/stdc++.h>
using namespace std;
int cnt[30];
set<int> used;
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    used.clear();
    int num = 0;
    memset(cnt, 0, sizeof(cnt));
    for (auto p : s) cnt[p - 'a']++;
    for (int i = 0; i < 26; i++)
      if (cnt[i]) num++;
    string ans, now, pre;
    int las = s.length() - 1;
    for (int i = num; i >= 1; i--) {
      char kkk;
      for (int u = las; u >= 0; u--) {
        if (!used.count(s[u])) {
          used.insert(s[u]);
          kkk = s[u];
          break;
        }
      }
      ans += kkk;
      if (cnt[kkk - 'a'] % i != 0) {
        cout << "-1\n";
        goto OVE;
      }
      pre = "";
      int k = cnt[kkk - 'a'] / i;
      int loc = 0, tmp = las;
      for (;; las--) {
        if (k == 0 && loc >= now.length()) break;
        if (loc < now.length() && now[loc] == s[las])
          loc++;
        else if (k > 0 && s[las] == kkk)
          k--;
        else {
          cout << "-1\n";
          goto OVE;
        }
        pre += s[las];
      }
      now = pre;
    }
    cout << now << " " << ans << "\n";
  OVE:;
  }
}
