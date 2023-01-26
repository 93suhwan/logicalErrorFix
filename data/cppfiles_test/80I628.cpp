#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
char s[MAXN];
void solve() {
  int n;
  scanf("%d%s", &n, s + 1);
  int mid = (n + 1) / 2;
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (flag) break;
    if (s[i] == '0') {
      if (i <= mid) {
        printf("%d %d %d %d\n", i, n, i + 1, n);
      } else {
        printf("%d %d %d %d\n", 1, i, 1, i - 1);
      }
      flag = 1;
    }
  }
  if (!flag) {
    printf("1 %d 2 %d\n", mid, 1 + mid);
  }
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
