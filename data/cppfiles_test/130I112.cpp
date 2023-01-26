#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int ans[10000 + 10];
int id[10000 + 10];
int getid(int a, int b, int c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  int d;
  cin >> d;
  return d;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i += 3) {
      id[i] = getid(i, i + 1, i + 2);
      if (id[i] == 0)
        x = i;
      else
        y = i;
    }
    int f, ff;
    int ms, ce;
    f = getid(x, x + 1, y);
    ff = getid(x, x + 1, y + 1);
    if (f == 0 && ff == 0) {
      ans[x] = ans[x + 1] = 0;
      ms = x;
      int cur = getid(y, y + 1, x);
      if (cur == 0) {
        ans[y + 2] = 1;
        ce = y + 2;
        ans[y] = getid(ms, ce, y);
        ans[y + 1] = getid(ms, ce, y + 1);
      } else {
        ce = y;
        ans[y] = ans[y + 1] = 1;
        ans[y + 2] = getid(ms, ce, y + 2);
      }
      ans[x + 2] = getid(ms, ce, x + 2);
    } else if (f == 1 && ff == 1) {
      ms = x + 2;
      ce = y;
      ans[x + 2] = 0;
      ans[y] = ans[y + 1] = 1;
      ans[y + 2] = getid(ms, ce, y + 2);
      ans[x] = getid(ms, ce, x);
      ans[x + 1] = getid(ms, ce, x + 1);
    } else {
      ms = x + 2, ce = y + 2;
      ans[ms] = 0, ans[ce] = 1;
      ans[x] = getid(ms, ce, x);
      ans[x + 1] = getid(ms, ce, x + 1);
      ans[y] = getid(ms, ce, y);
      ans[y + 1] = getid(ms, ce, y + 1);
    }
    for (int i = 1; i <= n; i += 3)
      if (i != x && i != y) {
        int l, r;
        if (id[i]) {
          l = getid(i, i + 1, ms);
          r = getid(i + 1, i + 2, ms);
          if (l == 0 && r == 0) {
            ans[i + 1] = 0;
            ans[i] = ans[i + 1] = 1;
          } else {
            ans[i + 1] = 1;
            ans[i] = l;
            ans[i + 2] = r;
          }
        } else {
          l = getid(i, i + 1, ce);
          r = getid(i + 2, i + 1, ce);
          if (l == 1 && r == 1) {
            ans[i + 1] = 1;
            ans[i] = ans[i + 2] = 0;
          } else {
            ans[i + 1] = 0;
            ans[i] = l;
            ans[i + 2] = r;
          }
        }
      }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
      if (!ans[i]) cnt++;
    printf("! %d ", cnt);
    for (int i = 1; i <= n; ++i)
      if (!ans[i]) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
