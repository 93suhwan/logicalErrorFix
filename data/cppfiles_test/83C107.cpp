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
const int N = 5005;
int n, f[N][N], t, g[N];
char s[N];
struct E {
  int l, r;
};
bool operator<(const E &a, const E &b) {
  int t = f[a.l][b.l];
  int l1 = a.r - a.l + 1, l2 = b.r - b.l + 1;
  if (t + 1 <= min(l1, l2)) {
    return s[a.l + t] < s[b.l + t];
  } else {
    return l1 < l2;
  }
}
bool operator==(const E &a, const E &b) {
  int l1 = a.r - a.l + 1, l2 = b.r - b.l + 1;
  if (l1 != l2) return 0;
  return f[a.l][b.l] >= l1;
}
int main() {
  int T;
  read(T);
  while (T--) {
    read(n);
    t = 0;
    scanf("%s", s + 1);
    for (int i = n; i; i--) {
      for (int j = n; j; j--) {
        if (s[i] == s[j]) f[i][j] = f[i + 1][j + 1] + 1;
      }
    }
    int ans = 0;
    for (int i = n; i; i--) {
      g[i] = 0;
      E u = (E){i, n};
      for (int j = i + 1; j <= n; j++) {
        E v = (E){j, n};
        if (u < v) {
          int t = f[i][j];
          chkMax(g[i], g[j] + n - j + 1 - t);
        }
      }
      chkMax(ans, g[i] + n - i + 1);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) f[i][j] = 0;
  }
  return 0;
}
