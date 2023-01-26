#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
char s[MAXN];
int a[20][MAXN];
string p[20];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  p[1] = " abc";
  p[2] = " acb";
  p[3] = " bac";
  p[4] = " bca";
  p[5] = " cab";
  p[6] = " cba";
  for (int i = 1; i <= 6; i++) {
    int now = 1;
    for (int j = 1; j <= n; j++) {
      a[i][j] = a[i][j - 1];
      if (p[i][now] != s[j]) a[i][j]++;
      if (now == 3) now = 1;
      now++;
    }
  }
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    long long minn = 1e15;
    for (int i = 1; i <= 6; i++) {
      minn = min(minn, 1ll * a[i][r] - a[i][l - 1]);
    }
    printf("%lld\n", minn);
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
