#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[10000 + 10];
int getid(int a, int b, int c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  int d;
  cin >> d;
  return d;
}
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    int ans, pre, k1, k2;
    for (int i = 3; i <= n; ++i) {
      ans = getid(i - 2, i - 1, i);
      if (i == 3)
        pre = ans;
      else if (pre != ans) {
        a[i] = ans;
        a[i - 3] = pre;
        k1 = i - 3;
        k2 = i;
        break;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i != k1 && i != k2) {
        a[i] = getid(i, k1, k2);
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
      if (!a[i]) cnt++;
    printf("! %d ", cnt);
    for (int i = 1; i <= n; ++i)
      if (!a[i]) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
