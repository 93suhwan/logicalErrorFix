#include <bits/stdc++.h>
using namespace std;
int t;
int count(string a) {
  int vis[10], cnt = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < a.size(); i++) {
    int x = a[i] - '0';
    if (!vis[x]) {
      cnt++;
      vis[x] = 1;
    }
  }
  return cnt;
}
long long to_int(string s) {
  long long ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans = ans * 10 + s[i] - '0';
  }
  return ans;
}
int main() {
  cin >> t;
  while (t--) {
    string s;
    int k;
    cin >> s >> k;
    long long ans = 0x3f3f3f3f3f3f3f3f;
    if (count(s) <= k) {
      cout << s << '\n';
      continue;
    }
    for (int i = 0; i < s.size(); i++) {
      for (char j = s[i] + 1; j <= '9'; j++) {
        string ss = s;
        ss[i] = j;
        for (int kk = i + 1; kk <= s.size(); kk++) {
          ss[kk] = ss[i];
        }
        if (count(ss) > k) continue;
        for (int kk = i + 1; kk < s.size(); kk++) {
          for (char r = '0'; r <= '9'; r++) {
            string sss = ss;
            sss[kk] = r;
            if (count(sss) <= k) {
              ss[kk] = r;
              break;
            }
          }
        }
        ans = min(ans, to_int(ss));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
