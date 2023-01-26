#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = '.';
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
inline void chmax(int &x, int y) { x = max(x, y); }
inline void chmin(int &x, int y) { x = min(x, y); }
const int MOD = 998244353;
inline int add(int x, int y) {
  return (x + y >= MOD) ? (x + y - MOD)
                        : ((x + y < 0) ? (x + y + MOD) : (x + y));
}
const int MAXN = 300005;
int n, q;
char rd[MAXN];
int a[MAXN];
int s[MAXN];
vector<int> v[MAXN * 2];
inline int val(int x) { return s[x]; }
signed main() {
  int test_case = read();
  while (test_case--) {
    n = read(), q = read();
    scanf("%s", rd + 1);
    for (int i = 1; i <= n; i++) {
      if (rd[i] == '+')
        a[i] = 1;
      else
        a[i] = -1;
      if (i % 2 == 1)
        s[i] = s[i - 1] + a[i];
      else
        s[i] = s[i - 1] - a[i];
      v[s[i] + n].push_back(i);
    }
    while (q--) {
      int l = read(), r = read();
      int c = s[r] - s[l - 1];
      if (l % 2 == 0) c = -c;
      vector<int> ans;
      if (c == 0) {
        puts("0");
        continue;
      } else if (c % 2 == 0) {
        ans.push_back(r);
        if (r % 2 == l % 2)
          c -= a[r];
        else
          c += a[r];
        r--;
      }
      if (c < 0)
        c = (c - 1) / 2;
      else
        c = (c + 1) / 2;
      if (l % 2 == 1)
        c += n + s[l - 1];
      else
        c = -c + n + s[l - 1];
      int tmp = *lower_bound(v[c].begin(), v[c].end(), l);
      ans.push_back(tmp);
      cout << ans.size() << endl;
      for (int i : ans) cout << i << ' ';
      cout << endl;
    }
  }
  return 0;
}
