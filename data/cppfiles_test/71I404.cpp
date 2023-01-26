#include <bits/stdc++.h>
using namespace std;
int a[150];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s = to_string(n);
    if (k == 1) {
      bool flag = true;
      for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) flag = false;
      }
      if (flag)
        cout << s << '\n';
      else {
        int x = -1;
        char c = '0';
        for (int i = 0; i < s.size(); i++) {
          c = max(c, s[i]);
          if (s[i] < s[i + 1]) {
            x = i;
            break;
          }
          if (s[i] != s[i + 1]) break;
        }
        if (x != -1) c = c + 1;
        for (int i = 0; i < s.size(); i++) cout << c;
        cout << '\n';
      }
    } else {
      int a[10] = {0};
      int cnt = 0;
      for (int i = 0; i < s.size(); i++) {
        if (!a[s[i] - '0']) {
          cnt++;
          a[s[i] - '0'] = 1;
        }
      }
      if (cnt <= 2)
        cout << s << '\n';
      else {
        cnt = 0;
        int x = -1;
        int y = -1;
        char c = '9';
        char p, q;
        for (int i = 0; i < s.size(); i++) {
          c = min(c, s[i]);
          if (s[i] != s[i + 1]) {
            cnt++;
            if (cnt == 1) y = i, p = s[i];
            x = i, q = s[i];
          }
          if (cnt == 2) break;
        }
        if (s[x] > s[x + 1]) {
          if (c <= s[x + 1]) c = max(p, q);
          for (int i = x + 1; i < s.size(); i++) s[i] = c;
        } else {
          c = s[y + 1] + 1;
          s[y + 1] = c;
          c = min(s[y + 1], s[y]);
          if (s[y] == s[y + 1]) c = '0';
          for (int i = y + 2; i < s.size(); i++) s[i] = c;
        }
        cout << s << '\n';
      }
    }
  }
  return 0;
}
