#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> a(10, 0);
    int k1 = k;
    int pos = s.size();
    for (int i = 0; i < s.size(); ++i) {
      a[s[i] - '0']++;
      if (a[s[i] - '0'] == 1) {
        --k1;
      }
      if (k1 == -1) {
        a[s[i] - '0']--;
        pos = i;
        break;
      }
    }
    if (pos == s.size()) {
      cout << s << '\n';
      continue;
    }
    int ch = -1;
    char smth;
    int zero = 0;
    bool ok = 0;
    for (int i = s[pos] - '0' + 1; i <= 9; ++i) {
      if (a[i] > 0) {
        ch = pos;
        smth = i + '0';
        ok = 1;
        break;
      }
    }
    if (!ok) {
      for (int i = pos - 1; i >= 0; --i) {
        if (a[s[i] - '0'] == 1 && s[i] != '9') {
          ch = i;
          a[s[i] - '0' + 1]++;
          smth = s[i] + 1;
          ok = 1;
        } else
          for (int j = s[i] - '0' + 1; j <= 9; ++j) {
            if (a[j] > 0) {
              ch = i;
              smth = j + '0';
              ok = 1;
              break;
            }
          }
        a[s[i] - '0']--;
        if (ok) break;
      }
    }
    if (ch != -1) {
      char minn;
      s[ch] = smth;
      int cnt = 0;
      for (int i = 0; i < 10; ++i) {
        if (a[i] > 0) ++cnt;
      }
      for (int i = 0; i < 10; ++i) {
        if (a[i] > 0) {
          minn = i + '0';
          break;
        }
      }
      if (cnt < k) minn = '0';
      for (int i = ch + 1; i < s.size(); ++i) {
        s[i] = minn;
      }
      cout << s << '\n';
    }
  }
}
