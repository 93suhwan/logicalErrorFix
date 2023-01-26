#include <bits/stdc++.h>
const int maxn = 1e3 + 5;
int n, a[maxn];
void solve(int i) {
  if (!i) i += 2;
  for (; i < n; i += 2)
    if (a[i] > a[i + 1]) std::swap(a[i], a[i + 1]);
}
bool judge() {
  for (int i = 1; i < n; ++i)
    if (a[i] > a[i + 1]) return false;
  return true;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int res = 0;
    for (int i = 1;; ++i) {
      if (judge()) {
        printf("%d\n", res);
        break;
      }
      solve(i & 1);
      res++;
    }
  }
  return 0;
}
