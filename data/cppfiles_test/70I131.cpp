#include <bits/stdc++.h>
using namespace std;
int t;
int p[32], c[32], d[32], h[32];
int main() {
  cin >> t;
  while (t--) {
    int flag = 0;
    memset(d, 0, sizeof(d));
    memset(c, 0, sizeof(c));
    memset(p, 0, sizeof(p));
    memset(h, -1, sizeof(h));
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      if (!d[s[i] - 'a']) {
        cnt++;
        d[s[i] - 'a'] = 1;
      } else {
        d[s[i] - 'a']++;
      }
    }
    for (int i = s.length(); i >= 0; i--) {
      if (!p[s[i] - 'a']) p[s[i] - 'a'] = cnt--;
    }
    for (int i = 0; i <= 25; i++) {
      h[p[i]] = i;
    }
    for (int i = 0; i <= 25; i++) {
      if (p[i] == 0) continue;
      c[i] = d[i] / p[i];
      if ((c[i] * p[i]) != d[i]) flag = 1;
    }
    if (flag)
      cout << -1 << endl;
    else {
      string ss;
      int sum = 0;
      for (int i = 0; i <= 25; i++) sum += c[i];
      int cnt1 = 0;
      for (int i = 0; i < s.length(); i++) {
        if (c[s[i] - 'a']) {
          c[s[i] - 'a']--;
          cnt1++;
          ss.push_back(s[i]);
        } else {
          break;
        }
      }
      if (cnt1 != sum) flag = 1;
      cnt1 = 0;
      int cnt2 = 0;
      for (int i = 0; i < s.length(); i++) {
        if (cnt1 == sum) {
          cnt1 = 0;
          cnt2++;
        }
        while (p[ss[cnt1] - 'a'] <= cnt2 && cnt < sum) cnt1++;
        if (cnt1 == sum) {
          cnt1 = 0;
          cnt2++;
        }
        while (p[ss[cnt1] - 'a'] <= cnt2 && cnt < sum) cnt1++;
        if (s[i] != ss[cnt1]) {
          flag = 1;
          break;
        } else {
          cnt1++;
        }
      }
      if (flag)
        cout << -1 << endl;
      else {
        cout << ss << " ";
        for (int i = 1; i <= 26; i++) {
          if (h[i] == -1)
            break;
          else {
            char q = 'a' + h[i];
            cout << q;
          }
        }
        cout << endl;
      }
    }
  }
  return 0;
}
