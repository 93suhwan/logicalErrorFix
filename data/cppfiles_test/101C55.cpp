#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int f = 1, x = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return f * x;
}
const int maxn = 200010;
int t, n, a[maxn], ans;
char c[maxn];
multiset<int> st1, st2;
int main() {
  for (scanf("%d", &t); t; t--) {
    scanf("%d", &n);
    ans = 1;
    st1.clear();
    st2.clear();
    for (register int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%s", c + 1);
    for (register int i = 1; i <= n; i++)
      if (c[i] == 'B')
        st1.insert(a[i]);
      else
        st2.insert(a[i]);
    for (register int i = 1; i <= n && ans; i++) {
      if (st1.empty() || *(--st1.end()) < i) {
        if (st2.empty() || *st2.begin() > i)
          ans = 0;
        else
          st2.erase(st2.begin());
      } else
        st1.erase(st1.lower_bound(i));
    }
    printf(ans ? "YES\n" : "NO\n");
  }
  return 0;
}
