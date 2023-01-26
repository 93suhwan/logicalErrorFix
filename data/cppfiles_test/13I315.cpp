#include <bits/stdc++.h>
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const long long INF64 = (long long)1e18;
const double INFD = 1e30;
const double EPS = 1e-9;
const double PI = std::acos(-1);
const int MOD = 998244353;
template <typename T>
inline T read() {
  T X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
const int MAXN = 105;
const int MAXV = (1 << 17) + 5;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;
int A[MAXN];
int C[26][MAXN];
int cnt[26];
char S[MAXN][MAXN];
int n, m, k;
int test(int i, int j, int a, int b) {
  for (int c = 0; c < 26; c++) {
    bool can = true;
    for (int s = 0; s < 4; s++) {
      int nr = dr[s] + i;
      int nc = dc[s] + j;
      if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        if (S[nr][nc] == c + 'a') {
          can = false;
          break;
        }
      }
    }
    for (int s = 0; s < 4; s++) {
      int nr = dr[s] + a;
      int nc = dc[s] + b;
      if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        if (S[nr][nc] == c + 'a') {
          can = false;
          break;
        }
      }
    }
    if (can) return c;
  }
  assert(false);
}
void placeH(int i, int j) {
  S[i][j] = S[i][j + 1] = test(i, j, i, j + 1) + 'a';
}
void placeV(int i, int j) {
  S[i][j] = S[i + 1][j] = test(i, j, i + 1, j) + 'a';
}
void solve() {
  scanf("%d%d%d", &n, &m, &k);
  if (!k && (n & 1)) {
    printf("NO\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) S[i][j] = -1;
  }
  if (n & 1) {
    int c = m / 2;
    if (k >= c && c * n >= k && (k - c) % 2 == 0) {
      printf("YES\n");
      for (int i = 0; i < c; i++) {
        placeH(0, i * 2);
        k--;
      }
      int j = 1;
      while (k > 0) {
        for (int i = 0; i < c; i++) {
          placeH(j, i * 2);
          placeH(j + 1, i * 2);
          k -= 2;
          if (k == 0) break;
        }
        j += 2;
      }
      assert(!k);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (S[i][j] == 255) {
            placeV(i, j);
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          fputc(S[i][j], stdout);
        }
        printf("\n");
      }
      return;
    }
  } else {
    int c = m / 2;
    if (k % 2 == 0 && c * n >= k) {
      printf("YES\n");
      int j = 0;
      while (k > 0) {
        for (int i = 0; i < c; i++) {
          placeH(j, i * 2);
          placeH(j + 1, i * 2);
          k -= 2;
          if (k == 0) break;
        }
        j += 2;
      }
      assert(!k);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (S[i][j] == -1) {
            placeV(i, j);
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          fputc(S[i][j], stdout);
        }
        printf("\n");
      }
      return;
    }
  }
  printf("NO\n");
}
int main() {
  int T = read<int>();
  while (T--) {
    solve();
  }
  return 0;
}
