#include <bits/stdc++.h>
using namespace std;
int a[200005];
int f[200005];
int n;
void run1(int x, int y) {
  for (int i = 0; i <= x + y; i += 2) {
    n++;
    a[n] = i;
  }
}
void run2(int x, int y) {
  int d = (x + y) / 2;
  int bre;
  if ((x + y) % 2 == 1) d++;
  for (int i = 0; i <= min(x, d); i++) {
    if (x - i <= d - 1) {
      bre = d + x - 2 * i;
      if (f[bre] == 0) {
        f[bre] = 1;
        n++;
        a[n] = bre;
      }
    }
  }
  for (int i = 0; i <= min(y, d); i++) {
    if (y - i <= d - 1) {
      bre = d + y - 2 * i;
      if (f[bre] == 0) {
        f[bre] = 1;
        n++;
        a[n] = bre;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    n = 0;
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    if (x == y)
      run1(x, y);
    else
      run2(x, y);
    cout << n << endl;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
