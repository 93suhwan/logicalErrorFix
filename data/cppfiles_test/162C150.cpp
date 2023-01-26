#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int h[maxn];
int t[maxn];
bool check(int x) {
  for (int i = 1; i <= n; i++) t[i] = h[i];
  int d;
  for (int i = n; i >= 3; i--) {
    if (t[i] < x) return false;
    d = t[i] - x;
    if (d > h[i]) d = h[i];
    d /= 3;
    t[i - 1] += d;
    t[i - 2] += d << 1;
  }
  if (t[2] < x) return false;
  if (t[1] < x) return false;
  return true;
}
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  int ans = 0;
  int maxk = 29;
  for (int k = maxk; k >= 0; k--) {
    if (check(ans | (1 << k))) ans |= (1 << k);
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) work();
  return 0;
}
