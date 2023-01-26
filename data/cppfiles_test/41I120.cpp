#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
char s[MAXN];
bool check(char a, char b, char c) {
  if (a == b || a == c || b == c) return 0;
  return 1;
}
int a[MAXN];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (!check(s[i], s[i + 1], s[i + 2]) && i <= n - 2) {
      a[i] = a[i - 1] + 1;
    } else {
      a[i] = a[i - 1];
    }
  }
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l == r) {
      printf("0\n");
      continue;
    }
    if (l == r - 1) {
      if (s[l] == s[r]) {
        printf("1\n");
      } else {
        printf("0\n");
      }
      continue;
    }
    if (l == r - 2) {
      if (!check(a[l], a[l + 1], a[l + 2])) {
        printf("1\n");
      } else {
        printf("0\n");
      }
      continue;
    }
    printf("%d\n", a[r - 2] - a[l - 1]);
  }
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
