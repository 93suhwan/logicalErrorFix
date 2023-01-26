#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkMax(T &x, T y) {
  if (y > x) x = y;
}
template <typename T>
void chkMin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
  x *= f;
}
const int N = 300005, S = N << 1;
int n, q, s[N], B = 3e5;
char g[N];
vector<int> e1[S], e2[S];
int inline g1(int x, int l) {
  x += B;
  int p = lower_bound(e1[x].begin(), e1[x].end(), l) - e1[x].begin();
  return e1[x][p];
}
int inline g2(int x, int l) {
  x += B;
  int p = lower_bound(e2[x].begin(), e2[x].end(), l) - e2[x].begin();
  return e2[x][p];
}
int inline get(int l, int r) {
  int t = s[r] - s[l - 1];
  if (t > 0) {
    int g = t / 2 + 1;
    int pos = g1(g + s[l - 1], l);
    return pos;
  } else {
    int g = t / 2 - 1;
    int pos = g2(g + s[l - 1], l);
    return pos;
  }
}
int main() {
  int T;
  read(T);
  while (T--) {
    read(n), read(q);
    scanf("%s", g + 1);
    for (int i = 1; i <= n; i++) {
      int v = g[i] == '+' ? 1 : -1;
      if (i % 2 == 0) v = -v;
      s[i] = s[i - 1] + v;
      if (v == 1) {
        e1[s[i] + B].push_back(i);
      } else {
        e2[s[i] + B].push_back(i);
      }
    }
    while (q--) {
      int l, r;
      read(l), read(r);
      int t = s[r] - s[l - 1];
      if (!t)
        puts("0");
      else if (t & 1) {
        puts("1");
        printf("%d\n", get(l, r));
      } else {
        puts("2");
        printf("%d %d\n", r, get(l, r - 1));
      }
    }
    for (int i = 1; i <= n; i++) {
      int v = g[i] == '+' ? 1 : -1;
      if (i % 2 == 0) v = -v;
      if (v == 1) {
        e1[s[i] + B].clear();
      } else {
        e2[s[i] + B].clear();
      }
    }
  }
  return 0;
}
