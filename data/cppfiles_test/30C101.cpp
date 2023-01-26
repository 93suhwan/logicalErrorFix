#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  int l, r;
  for (l = 0, r = a.size() - 1; l < r;) {
    if (a[l] != a[r]) break;
    l++;
    r--;
  }
  if (l >= r) {
    cout << "0\n";
    return;
  }
  int res = 10000000, res1 = 0, res2 = 0;
  char tmp1 = a[l], tmp2 = a[r];
  for (l = 0, r = a.size() - 1; l < r;) {
    if (a[l] != a[r]) {
      while (a[l] != a[r]) {
        if (a[l] == tmp1)
          l++;
        else if (a[r] == tmp1)
          r--;
        else
          break;
        res1++;
      }
      if (a[l] != a[r]) break;
    }
    l++;
    r--;
  }
  if (l >= r) res = res1;
  for (l = 0, r = a.size() - 1; l < r;) {
    if (a[l] != a[r]) {
      while (a[l] != a[r]) {
        if (a[l] == tmp2)
          l++;
        else if (a[r] == tmp2)
          r--;
        else
          break;
        res2++;
      }
      if (a[l] != a[r]) break;
    }
    l++;
    r--;
  }
  if (l >= r) {
    cout << min(res, res2) << "\n";
    return;
  }
  if (res != 10000000) {
    cout << res << "\n";
    return;
  }
  cout << "-1\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
