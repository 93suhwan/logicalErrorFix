#include <bits/stdc++.h>
using namespace std;
void test() {
  int n, m, c1, c2, c3, c4;
  cin >> n >> m >> c1 >> c2 >> c3 >> c4;
  if (c1 == c3 || c2 == c4) {
    cout << 0 << endl;
    return;
  }
  int ans = 0;
  bool flag1 = 1, flag2 = 1;
  while (c3 != c1 && c4 != c2) {
    if (c1 == n) {
      flag1 = 0;
    }
    if (c2 == m) flag2 = 0;
    if (c1 == 1) {
      flag1 = 1;
    }
    if (c2 == 1) {
      flag2 = 1;
    }
    ans++;
    if (flag1)
      c1++;
    else
      c1--;
    ;
    if (flag2)
      c2++;
    else
      c2--;
  }
  cout << ans << endl;
  return;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    test();
  }
}
