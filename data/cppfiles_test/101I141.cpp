#include <bits/stdc++.h>
using namespace std;
int b[202020], r[202020];
void solve() {
  int n, a[202020];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  string c;
  cin >> c;
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] < 1 and c[i] == 'B') flag = 0;
    if (a[i] > n and c[i] == 'R') flag = 0;
    if (c[i] == 'B') {
      if (a[i] >= n)
        continue;
      else
        b[a[i]]++;
    } else if (c[i] == 'R') {
      if (a[i] <= 1)
        continue;
      else
        r[a[i]]++;
    }
  }
  if (flag) {
    for (int i = 1; i < n; i++) {
      if (b[i] >= i + 1) flag = 0;
    }
    for (int i = n, j = 2; i > 1; i--, j++) {
      if (r[i] >= j) flag = 0;
    }
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  } else
    cout << "NO" << '\n';
  memset(b, 0, sizeof(b));
  memset(r, 0, sizeof(r));
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
