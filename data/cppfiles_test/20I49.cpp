#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmax(T &x, T y) {
  return (x < y) ? ((x = y), 1) : 0;
}
template <typename T>
inline bool chkmin(T &x, T y) {
  return (x > y) ? ((x = y), 1) : 0;
}
const int NN = 410;
int T, N, M, cnt[NN][NN];
char mat[NN][NN];
inline int cal(int u, int d, int l, int r, bool col) {
  if (col == 1)
    return cnt[d][r] - cnt[u - 1][r] - cnt[d][l - 1] + cnt[u - 1][l - 1];
  else
    return (r - l + 1) * (d - u + 1) -
           (cnt[d][r] - cnt[u - 1][r] - cnt[d][l - 1] + cnt[u - 1][l - 1]);
}
inline int jsl(int i, int u, int d) { return cal(u, d, i, i, 0); }
inline int jsh(int i, int l, int r) { return cal(i, i, l, r, 0); }
inline int jszj(int u, int d, int l, int r) { return cal(u, d, l, r, 1); }
inline int jsda(int u, int d, int l, int r) {
  return jsh(u, l + 1, r - 1) + jsh(d, l + 1, r - 1) + jsl(l, u + 1, d - 1) +
         jsl(r, u + 1, d - 1) + jszj(u + 1, d - 1, l + 1, r - 1);
}
int ans, stk[NN], top;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) scanf("%s", mat[i] + 1);
    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= M; ++j)
        cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1] +
                    (mat[i][j] == '1');
    ans = 1e9;
    for (int u = 1; u <= N; ++u) {
      for (int d = u + 4; d <= N; ++d) {
        int j = 1;
        for (int i = 4; i <= M; ++i) {
          while (i - j > 3 && jsda(u, d, j, i) >= jsda(u, d, j + 1, i)) ++j;
          if (i - j >= 3) {
            ans = min(ans, jsda(u, d, j, i));
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
