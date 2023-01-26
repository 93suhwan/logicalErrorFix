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
    int ans = INT_MAX;
    bool have = 0;
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
        int pos1 = ((int)id.size() - 1) / 2;
        int pos2 = (int)id.size() / 2;
        map<int, int> mp;
        int c = 0;
        for (int j = id[pos1]; j >= 0; j--) {
          if (s[j] == (char)(i + 'a')) {
            mp[c]++;
          } else {
            c++;
          }
        }
        c = 0;
        for (int j = id[pos2]; j < n; j++) {
          if (s[j] == (char)(i + 'a')) {
            if (mp.count(c)) {
              mp[c]--;
              res -= 2;
              if (mp[c] == 0) {
                mp.erase(c);
              }
            }
          } else {
            c++;
          }
        }
        if (id[pos2] != id[pos1]) {
          res -= id[pos2] - id[pos1] - 1;
        }
        ans = min(ans, res);
        have = 1;
      }
    }
    cout << (have ? ans : -1) << '\n';
  }
  return 0;
}
