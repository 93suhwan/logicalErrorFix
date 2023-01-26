#include <bits/stdc++.h>
using namespace std;
int a[300005];
void solve() {
  int n, q;
  string s;
  cin >> n >> q;
  cin >> s;
  int flag = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '+') {
      a[i + 1] = a[i] + flag;
    } else {
      a[i + 1] = a[i] - flag;
    }
    flag = -flag;
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if ((r - l + 1) & 1)
      cout << 1 << endl;
    else {
      if (a[r] == a[l - 1])
        cout << 0 << endl;
      else
        cout << 2 << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
