#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  short f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (x << 1) + (x << 3) + (c ^ 48);
  x *= f;
  return;
}
const int N = 4e5 + 5, K = 21;
int T;
int n;
int sta[N][K][2], stb[N][K][2];
int lg[N];
pair<int, int> a[N], b[N];
int A[N], B[N];
int getmina(int l, int r) {
  return min(sta[l][lg[r - l + 1]][0],
             sta[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]][0]);
}
int getmaxa(int l, int r) {
  return max(sta[l][lg[r - l + 1]][1],
             sta[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]][1]);
}
int getminb(int l, int r) {
  return min(stb[l][lg[r - l + 1]][0],
             stb[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]][0]);
}
int getmaxb(int l, int r) {
  return max(stb[l][lg[r - l + 1]][1],
             stb[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]][1]);
}
int main() {
  lg[0] = -1;
  for (int i = 1; i < N; ++i) lg[i] = lg[i >> 1] + 1;
  read(T);
  while (T--) {
    read(n);
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= 18; ++j)
        sta[i][j][0] = stb[i][j][0] = 0x3f3f3f3f,
        sta[i][j][1] = stb[i][j][1] = 0;
    for (int i = 1; i <= n; ++i) read(A[i]);
    for (int i = 1; i <= n; ++i) read(B[i]);
    for (int i = 1; i <= n; ++i) a[i] = {A[i], B[i]}, b[i] = {B[i], A[i]};
    sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i)
      sta[i][0][0] = sta[i][0][1] = a[i].second,
      stb[i][0][0] = stb[i][0][1] = b[i].second;
    for (int k = 1; k <= 18; ++k) {
      for (int i = 1; i <= n; ++i) {
        sta[i][k][0] = min(sta[i][k - 1][0], sta[i + (1 << k - 1)][k - 1][0]);
        sta[i][k][1] = max(sta[i][k - 1][1], sta[i + (1 << k - 1)][k - 1][1]);
        stb[i][k][0] = min(stb[i][k - 1][0], stb[i + (1 << k - 1)][k - 1][0]);
        stb[i][k][1] = max(stb[i][k - 1][1], stb[i + (1 << k - 1)][k - 1][1]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      int p1 = lower_bound(a + 1, a + n + 1, make_pair(A[i], B[i])) - a;
      if (p1 >= n || getmaxa(1, p1) >= getmina(p1 + 1, n)) {
        putchar('1');
        continue;
      }
      int p2 = lower_bound(b + 1, b + n + 1, make_pair(B[i], A[i])) - b;
      if (p2 >= n || getmaxb(1, p2) >= getminb(p2 + 1, n)) {
        putchar('1');
        continue;
      }
      putchar('0');
    }
    puts("");
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= 18; ++j)
        sta[i][j][0] = stb[i][j][0] = 0x3f3f3f3f,
        sta[i][j][1] = stb[i][j][1] = 0;
  }
  return 0;
}
