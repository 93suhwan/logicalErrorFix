#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[26] = {};
    string s1 = "";
    for (int i = s.length() - 1; i >= 0; i--) {
      int a1 = s[i] - 97;
      if (a[a1])
        a[a1]++;
      else {
        a[a1] = 1;
        s1 += s[i];
      }
    }
    int ct[26] = {};
    int round = s1.length();
    int sum = 0;
    int flag = 0;
    for (int i = 0; i < s1.length(); i++) {
      ct[s1[i] - 97] = a[s1[i] - 97] / round;
      if (a[s1[i] - 97] % round) flag = 1;
      sum += ct[s1[i] - 97];
      round--;
    }
    string ans = s.substr(0, sum);
    s = s.substr(sum);
    string ans1 = ans;
    round = s1.length();
    while (round--) {
      string nxt = "";
      for (int i = 0; i < ans1.length(); i++) {
        if (ans1[i] == s1[round]) continue;
        nxt += ans1[i];
      }
      if (nxt != s.substr(0, ans1.length() - ct[s1[round] - 97])) {
        flag = 1;
        break;
      }
      ans1 = nxt;
      s = s.substr(nxt.length());
    }
    reverse(s1.begin(), s1.end());
    if (flag) {
      cout << -1 << "\n";
      continue;
    }
    cout << ans << " " << s1 << "\n";
  }
  return 0;
}
