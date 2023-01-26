#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, l = 1, r, res[200500];
long long a[200500];
char s[200500];
int main() {
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  cin >> s + 1;
  for (i = 1; i <= n; i++) {
    if (s[i] == s[i - 1])
      res[i] = --l;
    else
      res[i] = ++r;
  }
  for (i = 1; i <= n; i++) {
    res[i] -= l - 1;
    cout << a[res[i]] << (((s[1] == 'L') ^ (res[i] & 1)) ? " R" : " L") << '\n';
  }
}
