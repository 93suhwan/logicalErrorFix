#include <bits/stdc++.h>
using namespace std;
int read() {
  int tot = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    tot = tot * 10 + c - '0';
    c = getchar();
  }
  return tot * fh;
}
void getstr(char *a) {
  char c = getchar();
  int len = 0;
  while (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9')))
    c = getchar();
  while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
         (c >= '0' && c <= '9')) {
    a[++len] = c;
    c = getchar();
  }
}
const int maxn = 4050;
int t, n, a[maxn], ans, tmp, f[maxn * 3];
void solve(int x) {
  for (int i = 1; i <= x / 2; i++) swap(a[i], a[x - i + 1]);
  ans++;
  f[ans] = x;
}
int main() {
  t = read();
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ans = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++)
      if ((a[i] % 2) != (i % 2)) {
        flag = false;
        break;
      }
    if (!flag) {
      cout << -1 << endl;
      continue;
    }
    for (int i = n; i >= 3; i -= 2) {
      if (a[i - 1] == (i - 1) && a[i] == i) continue;
      for (int j = 1; j <= i; j++)
        if (a[j] == i) tmp = j;
      if (tmp != 1) solve(tmp);
      for (int j = 1; j <= i; j++)
        if (a[j] == (i - 1)) tmp = j;
      if (tmp != 2) solve(tmp - 1);
      solve(i);
      for (int j = 1; j <= i; j++)
        if (a[j] == i) tmp = j;
      if (tmp != 1) solve(tmp);
      solve(i);
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) cout << f[i] << " ";
    if (ans != 0) cout << endl;
  }
  return 0;
}
