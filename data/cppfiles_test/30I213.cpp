#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = 1;
    for (int i = 0; i <= n - 1 - i; i++) {
      if (s[i] != s[n - 1 - i]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << 0 << '\n';
      continue;
    }
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
      cnt[(int)(s[i] - 'a')]++;
    }
    int ans = -1;
    for (int i = 0; i < 26; i++) {
      if (cnt[i]) {
        string t = "";
        vector<int> id;
        for (int j = 0; j < n; j++) {
          if (s[j] != (char)(i + 'a')) {
            t += s[j];
            id.emplace_back(j);
          }
        }
        bool ok = 1;
        for (int j = 0; j <= (int)t.size() - 1 - j; j++) {
          if (t[j] != t[(int)t.size() - 1 - j]) {
            ok = 0;
            break;
          }
        }
        if (!ok) {
          continue;
        }
        int res = cnt[i];
        int pos = ((int)id.size() - 1) / 2;
        for (int j = 0; id[pos] + j < n and id[pos] - j >= 0; j++) {
          if (s[id[pos] + j] == s[id[pos] - j] and
              s[id[pos] + j] == (char)(i + 'a')) {
            res -= 2;
          }
        }
        if (ans == -1) {
          ans = res;
        } else {
          ans = min(ans, res);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
