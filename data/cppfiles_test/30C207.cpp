#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const long long N = 200010;
inline long long read() {
  long long s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long n;
char s[N];
inline long long Get(char x) {
  string t = "";
  for (register long long i = 1; i <= n; i++) {
    if (s[i] != x) t += s[i];
  }
  for (register long long i = 0; i < (long long)t.size() / 2; i++) {
    if (t[i] != t[(long long)t.size() - i - 1]) return 1e9;
  }
  long long l = 1, r = n, go = 0;
  while (l <= r) {
    if (s[l] == s[r])
      l++, r--;
    else if (s[l] == x && s[r] != x)
      l++, go++;
    else
      r--, go++;
  }
  return go;
}
signed main() {
  for (register long long T = read(); T; T--) {
    n = read();
    scanf("%s", s + 1);
    long long ans = 1e9;
    for (register long long i = 0; i < 26; i++) {
      ans = min(Get((char)(i + 'a')), ans);
    }
    if (ans < 1e9)
      printf("%d\n", ans);
    else
      puts("-1");
  }
  return 0;
}
