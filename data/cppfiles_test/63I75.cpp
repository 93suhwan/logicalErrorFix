#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 6;
int n, f[1 << 20];
struct STR {
  char s[N];
  int pos[N], len, nx[N], tp[N], rest[N], step[N];
  int k;
  void init() {
    len = strlen(s + 1);
    static int sta[N];
    int top = 0;
    for (int i = 1; i <= len; ++i)
      if (s[i] == '(') {
        sta[++top] = i;
      } else {
        if (top && s[sta[top]] == '(')
          nx[sta[top--]] = i + 1;
        else {
          sta[++top] = i;
          if (!pos[top]) pos[top] = i;
        }
      }
    top = 0;
    for (int i = len; i; --i) {
      if (s[i] == '(') {
        if (top && s[sta[top]] == ')')
          --top;
        else
          sta[++top] = i;
      } else
        sta[++top] = s[i];
      if (!top || s[sta[top]] == '(')
        rest[i] = top;
      else
        rest[i] = -1;
    }
    tp[len + 1] = len + 1;
    for (int i = len; i; --i) {
      if (nx[i]) {
        tp[i] = tp[nx[i]];
        step[i] = step[nx[i]] + 1;
      } else {
        tp[i] = i;
        step[i] = 0;
      }
    }
    for (int i = 1; i <= len; ++i)
      if (s[i] == '(')
        ++k;
      else
        --k;
  }
} a[21];
int ans;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> (a[i].s + 1);
  for (int i = 0; i < n; ++i) a[i].init();
  memset(f, -1, sizeof f);
  for (int i = 0; i < n; ++i) {
    int p = a[i].tp[1], Step = a[i].step[1];
    ans = max(ans, Step);
    if (a[i].rest[p] != -1) f[1 << i] = Step;
  }
  for (int c = 1; c < n; ++c)
    for (int S = 1; S < 1 << n; ++S)
      if (__builtin_popcount(S) == c && f[S] != -1) {
        int t = 0;
        for (int i = 0; i < n; ++i)
          if (S >> i & 1) t += a[i].k;
        if (t < 0) continue;
        for (int j = 0; j < n; ++j)
          if (!(S >> j & 1)) {
            if (a[j].pos[t] != 0 || t == 0) {
              int p = (t == 0) ? 1 : a[j].pos[t] + 1;
              int val = f[S] + a[j].step[p] + !!t;
              p = a[j].tp[p];
              ans = max(ans, val);
              if (a[j].rest[p] != -1) f[S | 1 << j] = max(f[S | 1 << j], val);
            } else
              f[S | 1 << j] = max(f[S | 1 << j], f[S]);
          }
      }
  cout << ans << '\n';
  return 0;
}
