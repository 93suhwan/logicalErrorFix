#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve() {
  int s[20001];
  pair<int, int> ps[20001];
  int rp = 0, rm = 0;
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    char p;
    cin >> p;
    if (p == '+') {
      s[i] = 1;
      rp++;
    } else {
      s[i] = -1;
      rm++;
    }
    ps[i] = make_pair(rp, rm);
  }
  bool a = false;
  if (!(ps[n].first - ps[n].second)) a = true;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (n == 0)
      cout << 0 << nl;
    else {
      int x;
      if (a) {
        x = abs(abs(ps[l - 1].first - ps[r].first) -
                abs(ps[l - 1].second - ps[r].second)) == 0
                ? 2
                : abs(abs(ps[l - 1].first - ps[r].first) -
                      abs(ps[l - 1].second - ps[r].second));
      } else {
        x = abs(abs(ps[l - 1].first - ps[r].first) -
                abs(ps[l - 1].second - ps[r].second));
      }
      cout << x << nl;
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
