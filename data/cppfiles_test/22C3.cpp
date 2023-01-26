#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxn = 2e5 + 5, maxs = 450;
int n, m, x[maxn], y[maxn], t[maxn];
int S, B, c[maxs][maxs];
int pos[maxn], L[maxs], R[maxs], s1[maxn], s2[maxs];
void modify(int x, int k) {
  s1[x] += k;
  s2[pos[x]] += k;
}
int query(int x) {
  int s = 0;
  for (int i = 1; i < pos[x]; i++) s += s2[i];
  for (int i = L[pos[x]]; i <= x; i++) s += s1[i];
  return s;
}
int main() {
  n = readint();
  m = readint();
  for (int i = 1; i <= n; i++) {
    x[i] = readint();
    y[i] = readint();
  }
  S = sqrt(m);
  B = (m - 1) / S + 1;
  for (int i = 1; i <= B; i++) {
    L[i] = (i - 1) * S + 1;
    R[i] = min(i * S, m);
    for (int j = L[i]; j <= R[i]; j++) pos[j] = i;
  }
  for (int i = 1; i <= m; i++) {
    int op, k;
    op = readint();
    k = readint();
    if (op == 1) t[k] = i;
    if (x[k] + y[k] <= S)
      for (int j = t[k] + x[k]; j < t[k] + x[k] + y[k]; j++)
        c[x[k] + y[k]][j % (x[k] + y[k])] += op == 1 ? 1 : -1;
    else
      for (int j = 0; t[k] + (x[k] + y[k]) * j + x[k] <= m; j++) {
        modify(t[k] + (x[k] + y[k]) * j + x[k], op == 1 ? 1 : -1);
        if (t[k] + (x[k] + y[k]) * (j + 1) <= m)
          modify(t[k] + (x[k] + y[k]) * (j + 1), op == 1 ? -1 : 1);
      }
    int ans = query(i);
    for (int j = 1; j <= S; j++) ans += c[j][i % j];
    printf("%d\n", ans);
  }
  return 0;
}
