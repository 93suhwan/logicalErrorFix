#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int d[2] = {0, 0};
  int l[2] = {0, 0};
  int tp[2] = {n, n};
  vector<int> p(n);
  vector<int> s(n);
  bool fail = false;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (fail) continue;
    bool ok = false;
    for (int k = 0; k < 2; k++) {
      s[i] = k;
      if (l[k] == 0) {
        l[k] = p[i];
        d[k] = -1;
        ok = true;
        break;
      }
      if (d[k] == -1) {
        if (p[i] < l[k]) {
          l[k] = p[i];
        } else {
          d[k] = 1;
          tp[k] = i;
          l[k] = p[i];
        }
        ok = true;
        break;
      }
      if (p[i] > l[k]) {
        l[k] = p[i];
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << endl;
      fail = true;
    }
  }
  if (fail) return;
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    if (i >= tp[s[i]]) {
      cout << p[i] << " ";
    } else {
      cout << -p[i] << " ";
    }
  }
  cout << endl;
}
int main() {
  int ncases;
  cin >> ncases;
  for (int i = 1; i <= ncases; i++) {
    solve();
  }
  return 0;
}
