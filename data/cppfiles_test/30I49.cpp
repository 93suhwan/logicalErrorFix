#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int ret = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9'; ch = getchar()) ret = ret * 10 + ch - '0';
  return ret * f;
}
int cnt[30];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    bool flag = 1;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - i - 1]) {
        ans = -1;
        break;
      }
    }
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    if (ans == -1)
      for (char a = 'a'; a <= 'z'; a++) {
        bool st = 1;
        for (int i = 0, j = n - 1; i < j;) {
          while (s[i] == a && i < j) i++;
          while (s[j] == a && i < j) j--;
          if (i < j && s[i] != s[j]) {
            st = 0;
            break;
          }
          i++, j--;
        }
        if (st) {
          if (ans == -1) ans = cnt[a - 'a'];
          ans = min(ans, cnt[a - 'a']);
        }
      }
    cout << ans << endl;
  }
  return 0;
}
