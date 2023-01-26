#include <bits/stdc++.h>
using namespace std;
char rev(char c) { return c == 'L' ? 'R' : 'L'; }
int n, a[200005];
char s[200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> s + 1;
  sort(a + 1, a + n + 1);
  int revc = 0;
  for (int i = 1; i <= n; i++) revc += s[i] != s[i - 1];
  for (int i = 1; i <= revc; i++) swap(a[i], a[i + n - revc]);
  reverse(a + revc + 1, a + n + 1);
  char d = 0;
  int crit = 0;
  int w = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] != s[i - 1]) {
      cout << a[++crit] << ' ' << s[i] << '\n';
      w = a[crit] - w;
      d = 0;
    } else {
      if (!d)
        d = w > a[revc + 1] ? rev(s[i]) : s[i];
      else
        d = rev(d);
      cout << a[++revc] << ' ' << d << '\n';
      w = d == s[i] ? w + a[revc] : w - a[revc];
    }
  return 0;
}
