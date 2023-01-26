#include <bits/stdc++.h>
using namespace std;
int a[60], ans[60];
int l[60], r[60], d[60];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      ans[i] = a[i];
    }
    sort(ans + 1, ans + 1 + n);
    int cnt = 0;
    for (i = 1; i < n; i++) {
      for (j = i; j <= n; j++) {
        if (a[j] == ans[i]) {
          for (int k = j; k > i; k--) a[k] = a[k - 1];
          break;
        }
      }
      if (j != i) {
        l[cnt] = i, r[cnt] = j, d[cnt] = j - i;
        cnt++;
      }
    }
    cout << cnt << endl;
    for (i = 0; i < cnt; i++)
      cout << l[i] << ' ' << r[i] << ' ' << d[i] << endl;
  }
  return 0;
}
