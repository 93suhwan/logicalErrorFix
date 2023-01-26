#include <bits/stdc++.h>
using namespace std;
int f1[1004];
int f2[1004];
int xx[1004];
int yy[1005];
int biger1(int x) {
  int r = x;
  while (x != f1[x]) x = f1[x];
  int j, ff = x;
  while (x != f1[r]) {
    j = f1[r];
    f1[r] = x;
    r = j;
  }
  return ff;
}
bool mix1(int x, int y) {
  int f11 = biger1(x), f21 = biger1(y);
  if (f11 != f21) {
    f1[f11] = f21;
    return true;
  }
  return false;
}
int biger2(int x) {
  int r = x;
  while (x != f2[x]) x = f2[x];
  int j, ff = x;
  while (x != f2[r]) {
    j = f2[r];
    f2[r] = x;
    r = j;
  }
  return ff;
}
bool mix2(int x, int y) {
  int f11 = biger2(x), f21 = biger2(y);
  if (f11 != f21) {
    f2[f11] = f21;
    return true;
  }
  return false;
}
bool mixx(int x, int y) {
  int f11 = biger1(x);
  int f12 = biger1(y);
  int f21 = biger2(x);
  int f22 = biger2(y);
  if (f11 != f12 && f21 != f22) {
    f1[f11] = f12;
    f2[f21] = f22;
    return true;
  }
  return false;
}
void solve() {
  int n, m1, m2;
  scanf("%d%d%d", &n, &m1, &m2);
  for (int i = 1; i <= n; i++) {
    f1[i] = i;
    f2[i] = i;
  }
  int l, r;
  for (int i = 1; i <= m1; i++) {
    scanf("%d%d", &l, &r);
    if (mix1(l, r))
      continue;
    else {
      puts("0");
      return;
    }
  }
  for (int i = 1; i <= m2; i++) {
    scanf("%d%d", &l, &r);
    if (mix2(l, r))
      continue;
    else {
      puts("0");
      return;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (mixx(i, j)) {
        ans++;
        xx[ans] = i;
        yy[ans] = j;
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) {
    printf("%d %d\n", xx[i], yy[i]);
  }
}
int main() { solve(); }
