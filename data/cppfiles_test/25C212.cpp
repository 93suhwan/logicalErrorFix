#include <bits/stdc++.h>
using namespace std;
string a, b;
int ans;
int fun(int pos, int f, int s) {
  if (s == b.size()) {
    return 1;
  }
  if (f == 0) {
    if (a[pos + 1] == b[s]) {
      ans += fun(pos + 1, 0, s + 1);
    }
    if (a[pos - 1] == b[s]) {
      ans += fun(pos - 1, 1, s + 1);
    }
  } else {
    if (a[pos - 1] == b[s]) {
      ans += fun(pos - 1, 1, s + 1);
    }
  }
  if (!ans) {
    return 0;
  } else
    return 1;
}
void solve() {
  ;
  cin >> a >> b;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[0]) {
      ans = 0;
      if (fun(i, 0, 1)) {
        cout << "YES" << '\n';
        ;
        return;
      }
    }
  }
  cout << "NO" << '\n';
  ;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
