#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const int MAXN = 3e5 + 11;
int cas, N, M, p[MAXN], S[MAXN], tmp[MAXN], vis[MAXN], Ans[MAXN], A[MAXN];
int main() {
  cas = read();
  while (cas--) {
    N = read(), M = read();
    for (int i = 1; i <= N; i++) A[read()] = i, S[i] = 0;
    for (int i = 1; i <= N; i++) {
      int x = i - A[i] + 1;
      if (x >= 1)
        S[x]++;
      else
        S[x + N]++;
    }
    bool ff = 0;
    Ans[0] = 0;
    for (int i = 1; i <= N; i++)
      if (S[i] >= N - 2 * M) {
        tmp[0] = 0;
        for (int j = i; j <= N; j++) tmp[++tmp[0]] = A[j];
        for (int j = 1; j < i; j++) tmp[++tmp[0]] = A[j];
        int cc = 0;
        for (int j = 1; j <= N; j++) vis[j] = 0;
        for (int j = 1; j <= N; j++)
          if (!vis[j]) {
            ++cc;
            int cur = j;
            while (!vis[cur]) vis[cur] = 1, cur = tmp[cur];
          }
        if (cc >= N - M) {
          Ans[++Ans[0]] = ((i != 1) ? N - i + 1 : 0);
        }
      }
    printf("%d ", Ans[0]);
    sort(Ans + 1, Ans + Ans[0] + 1);
    for (int i = 1; i <= Ans[0]; i++) printf("%d ", Ans[i]);
    printf("\n");
  }
  return 0;
}
