#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int cnt[30];
int main() {
  int T;
  cin >> T;
  while (T--) {
    bool st = true;
    memset(cnt, 0, sizeof cnt);
    string s;
    cin >> s;
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--)
      if (cnt[s[i] - 'a']++ == 0) ans += s[i];
    reverse(ans.begin(), ans.end());
    int front_num = 0;
    for (int i = 0; i < ans.size(); i++)
      if (cnt[ans[i] - 'a'] % (i + 1) != 0) {
        break;
      } else {
        front_num += (cnt[ans[i] - 'a'] / (i + 1));
      }
    string p = s.substr(0, front_num);
    string r = "";
    for (char c : ans) {
      r += p;
      p.erase(remove(p.begin(), p.end(), c), p.end());
    }
    if (r == s)
      cout << s.substr(0, front_num) << " " << ans << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
