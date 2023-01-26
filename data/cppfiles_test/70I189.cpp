#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1 << 30;
const long long inff = 1ll << 60;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
string s, s2, s1, s3;
int l, f[35], ans2[35], cnt2, cnt1, cnt, g[35], ok, anscnt;
void solve() {
  cin >> s;
  l = s.size();
  for (int i = 0; i < 26; i++) f[i] = g[i] = 0;
  cnt2 = 0;
  for (int i = l - 1; i >= 0; i--) {
    if (!f[s[i] - 'a']) ans2[++cnt2] = s[i] - 'a';
    f[s[i] - 'a']++;
  }
  ok = 1;
  for (int i = 1; i <= cnt2; i++)
    if (f[ans2[i]] % (cnt2 - i + 1) != 0) {
      puts("-1");
      return;
    } else
      f[ans2[i]] /= (cnt2 - i + 1);
  if (!ok)
    puts("-1");
  else {
    cnt = cnt1 = 0;
    anscnt = l;
    s1 = s2 = "";
    int sz = 0;
    for (int i = 0; i < l; i++) {
      s1 += s[i];
      g[s[i] - 'a']++;
      if (f[s[i] - 'a'] == g[s[i] - 'a'])
        cnt++;
      else if (f[s[i] - 'a'] < g[s[i] - 'a']) {
        puts("-1");
        return;
      }
      if (cnt == cnt2) {
        s3 = s1;
        anscnt = i;
        sz = s1.size();
        for (int i = 0; i < sz; i++)
          if (s1[i] - 'a' == ans2[cnt2]) s1.erase(i, 1);
        sz = s1.size();
        break;
      }
    }
    if (anscnt == l) ok = 0;
    int now = cnt2 - 1;
    for (int i = anscnt + 1; i < l && ok; i++) {
      s2 += s[i];
      if (s2 > s1 || i - anscnt > sz) {
        puts("-1");
        return;
      } else if (s2 == s1) {
        s2 = "";
        anscnt = i;
        for (int i = sz - 1; i >= 0; i--)
          if (s1[i] - 'a' == ans2[now]) s1.erase(i, 1);
        sz = s1.size();
        now--;
      }
    }
    cout << s3 << ' ';
    for (int i = cnt2; i; i--) putchar(ans2[i] + 'a');
    cout << '\n';
  }
}
int main() {
  int tests = 1;
  tests = read();
  while (tests--) {
    solve();
  }
  return 0;
}
