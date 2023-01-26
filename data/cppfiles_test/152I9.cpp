#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000005;
const int Inf = 1000000000;
int T;
int n;
int p[Maxn];
bool tk[Maxn];
int res[Maxn];
void Print() {
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%d%c", res[i], i + 1 <= n ? ' ' : '\n');
}
bool Positive() {
  fill(tk, tk + n + 1, false);
  int pnt = n;
  int mn = Inf;
  for (int i = n; i > 0; i--) {
    while (tk[pnt]) pnt--;
    if (p[i] == pnt)
      res[i] = p[i];
    else if (p[i] < mn)
      res[i] = p[i];
    else if (-p[i] < mn)
      res[i] = -p[i];
    else
      return false;
    tk[p[i]] = true;
    mn = min(mn, res[i]);
  }
  return true;
}
bool Negative() {
  fill(tk, tk + n + 1, false);
  int pnt = n;
  int mx = -Inf;
  for (int i = 1; i <= n; i++) {
    while (tk[pnt]) pnt--;
    if (p[i] == pnt)
      res[i] = -p[i];
    else if (-p[i] > mx)
      res[i] = -p[i];
    else if (p[i] > mx)
      res[i] = p[i];
    else
      return false;
    tk[p[i]] = true;
    mx = max(mx, res[i]);
  }
  return true;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    if (Positive())
      Print();
    else if (Negative())
      Print();
    else
      printf("NO\n");
  }
  return 0;
}
