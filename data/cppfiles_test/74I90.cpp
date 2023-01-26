#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 2e6 + 5;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
int n;
int a[N], b[N];
pair<int, int> var[M];
bool vis[M];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(b[i]);
  sort(b + 1, b + n + 1);
  int tot = unique(b + 1, b + n + 1) - b - 1;
  if (tot < n) {
    for (int i = 1; i <= tot; i++) a[i] = b[i];
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (b[i] & 1) {
      int p1 = 0, p2 = 0;
      for (int j = 1; j <= n; j++)
        if (i != j && (b[j] & 1)) p1 = j;
      for (int j = 1; j <= n; j++)
        if (i != j && (b[j] & 1 ^ 1)) p2 = j;
      if (!p1 || !p2) continue;
      a[i] = (-b[i] + b[p1] + b[p2]) / 2;
      for (int j = 1; j <= n; j++)
        if (i != j) a[j] = b[j] - a[i];
      puts("YES");
      for (int i = 1; i <= n; i++) printf("%d ", a[i]);
      puts("");
      return 0;
    } else {
      int p1 = 0, p2 = 0;
      for (int j = 1; j <= n; j++)
        if (i != j && (b[j] & 1)) {
          p1 = j;
          break;
        }
      for (int j = p1 + 1; j <= n; j++)
        if (i != j && (b[j] & 1)) {
          p2 = j;
          break;
        }
      if (!p1 || !p2) {
        p1 = 0, p2 = 0;
        for (int j = 1; j <= n; j++)
          if (i != j && (b[j] & 1 ^ 1)) {
            p1 = j;
            break;
          }
        for (int j = p1 + 1; j <= n; j++)
          if (i != j && (b[j] & 1 ^ 1)) {
            p2 = j;
            break;
          }
      }
      if (!p1 || !p2) continue;
      a[i] = (-b[i] + b[p1] + b[p2]) / 2;
      for (int j = 1; j <= n; j++)
        if (i != j) a[j] = b[j] - a[i];
      puts("YES");
      for (int i = 1; i <= n; i++) printf("%d ", a[i]);
      puts("");
      return 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (vis[b[j] - b[i]]) {
        int x = var[b[j] - b[i]].first, y = var[b[j] - b[i]].second;
        if (x == i || x == j || y == i || y == j) continue;
        for (int k = 1; k <= n; k++)
          if (k != x && k != y && k != i && k != j) a[k] = b[k];
        a[x] = b[x], a[y] = b[y];
        a[i] = 0, a[j] = b[i] - b[x];
        puts("YES");
        for (int k = 1; k <= n; k++) printf("%d ", a[k]);
        puts("");
        return 0;
      } else {
        vis[b[j] - b[i]] = true;
        var[b[j] - b[i]] = make_pair(i, j);
      }
  puts("NO");
  return 0;
}
