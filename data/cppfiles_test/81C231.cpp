#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve() {
  pair<int, int> ps[300001];
  int rp = 0, rm = 0;
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    char p;
    cin >> p;
    if (i % 2 != 0) {
      if (p == '+') {
        rp++;
      } else {
        rm++;
      }
    } else {
      if (p == '-') {
        rp++;
      } else {
        rm++;
      }
    }
    ps[i] = make_pair(rp, rm);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (n == 0)
      cout << 0 << nl;
    else {
      int x = abs(abs(ps[l - 1].first - ps[r].first) -
                  abs(ps[l - 1].second - ps[r].second));
      if (x % 2 == 0 && x != 0)
        cout << 2 << nl;
      else if (x % 2 != 0)
        cout << 1 << nl;
      else
        cout << 0 << nl;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
