#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-10, pi = acos(-1);
const int N = 1e6 + 10, M = 1e7 + 10, ha = 131, INF = 0x3f3f3f3f, mod = 31607;
int n;
int a[N];
int s[N];
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < (1 << n); i++) {
    s[i] = 0;
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) s[i] += a[j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      printf("YES\n");
      return;
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    for (int j = 1; j < (1 << n); j++) {
      if ((i & j) == 0 && (s[i] == s[j] || s[i] == -s[j])) {
        printf("YES\n");
        return;
      }
    }
  }
  printf("NO\n");
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
