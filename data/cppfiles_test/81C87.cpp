#include <bits/stdc++.h>
using namespace std;
int a[300010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    memset(a, 0, sizeof(a));
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        if (s[i] == '+')
          a[i + 1] = a[i] - 1;
        else
          a[i + 1] = a[i] + 1;
      } else {
        if (s[i] == '+')
          a[i + 1] = a[i] + 1;
        else
          a[i + 1] = a[i] - 1;
      }
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      if ((r - l + 1) & 1)
        cout << 1 << "\n";
      else {
        if (a[r] - a[l - 1] == 0)
          cout << 0 << "\n";
        else
          cout << 2 << "\n";
      }
    }
  }
  return 0;
}
