#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int t, n, m, a[N], pre1[N], pre2[N];
void solve() {
  int l, r;
  memset(pre1, 0, sizeof(pre1));
  memset(pre2, 0, sizeof(pre2));
  string s;
  scanf("%d%d", &n, &m);
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '+') {
      if (i & 1)
        a[i + 1] = -1;
      else
        a[i + 1] = 1;
    } else if (s[i] == '-') {
      if (i & 1)
        a[i + 1] = 1;
      else
        a[i + 1] = -1;
    }
  }
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  while (m--) {
    scanf("%d%d", &l, &r);
    int tem = a[r] - a[l - 1];
    if (tem == 0) {
      printf("0\n");
    } else if (tem & 1) {
      printf("1\n");
    } else {
      printf("2\n");
    }
  }
}
int main() {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
