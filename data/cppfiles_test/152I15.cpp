#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000005;
const int Inf = 1000000000;
int T;
int n;
int p[Maxn];
int L[Maxn], R[Maxn];
bool posL[Maxn], posR[Maxn];
bool tk[Maxn];
int res[Maxn];
void writeL(int ind) {
  for (int i = 1; i <= ind; i++) res[i] = L[i];
}
void writeR(int ind) {
  for (int i = ind; i <= n; i++) res[i] = R[i];
}
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
      if (posL[i - 1]) {
        res[i] = -p[i];
        writeL(i - 1);
        return true;
      } else
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
      if (posR[i + 1]) {
        res[i] = p[i];
        writeR(i + 1);
        return true;
      } else
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
    L[0] = -Inf;
    posL[0] = true;
    for (int i = 1; i <= n; i++)
      if (!posL[i - 1])
        posL[i] = false;
      else if (-p[i] > L[i - 1])
        L[i] = -p[i];
      else if (p[i] > L[i - 1])
        L[i] = p[i];
      else
        posL[i] = false;
    R[n + 1] = Inf;
    posR[n + 1] = true;
    for (int i = n; i > 0; i--)
      if (!posR[i + 1])
        posR[i] = false;
      else if (p[i] < R[i + 1])
        R[i] = p[i];
      else if (-p[i] < R[i + 1])
        R[i] = -p[i];
      else
        posR[i] = false;
    if (Positive())
      Print();
    else if (Negative())
      Print();
    else
      printf("NO\n");
  }
  return 0;
}
