#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
char s[N];
int a[N];
signed main() {
  freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
  ;
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      a[i] = a[i - 1] + (s[i] == '+' ? 1 : -1) * (i % 2 == 0 ? 1 : -1);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--;
      if ((r - l) % 2 == 1) {
        cout << "1\n";
      } else if (a[l] == a[r]) {
        cout << "0\n";
      } else {
        cout << "2\n";
      }
    }
  }
  return 0;
}
