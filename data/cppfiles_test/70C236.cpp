#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    string o = "";
    int a[26] = {0};
    int sum = 0;
    for (auto c : t) {
      if (a[c - 'a'] == 0) {
        sum++;
        o += c;
        a[c - 'a'] = 1;
      }
    }
    if (sum == 1) {
      cout << s << " " << s[0] << "\n";
      continue;
    }
    reverse(o.begin(), o.end());
    char f = o[0];
    char s1;
    for (auto c : s) {
      if (c != f) {
        s1 = c;
        break;
      }
    }
    string s2 = "";
    int e1 = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == s1 && s2.size() != 0 && sum == 0) {
        if (s.substr(i, s2.size()) == s2) {
          e1 = i;
        }
      }
      if (a[s[i] - 'a'] == 1) {
        a[s[i] - 'a'] = 0;
        sum--;
      }
      if (s[i] != f) {
        s2 += s[i];
      }
    }
    if (e1 == -1) {
      cout << -1 << "\n";
      continue;
    }
    string ans = s.substr(0, e1);
    string tf = ans;
    string curr = ans;
    for (auto c : o) {
      string temp = "";
      for (auto e : curr) {
        if (e != c) {
          temp += e;
        }
      }
      if (temp.size() > 0) tf += temp;
      curr = temp;
    }
    if (s != tf) {
      cout << -1 << "\n";
    } else {
      cout << ans << " " << o << "\n";
    }
  }
  return 0;
}
