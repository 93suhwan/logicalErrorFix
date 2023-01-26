#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int mx = 1e6;
int posx[] = {1, -1, 0, 0};
int posy[] = {0, 0, 1, -1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1, n, k, r1, r2, c1, c2, d1, d2, a, b, c, d;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    vector<int> ans(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    int pos = 1, f = 0, aa = a, bb = b;
    while (pos < n && (a > 0 || b > 0)) {
      int it = *s.begin();
      if (aa > bb) {
        if (pos & 1)
          it = *s.begin(), b--;
        else
          it = *s.rbegin(), a--;
        f = 0;
        b += (pos == 1);
      } else {
        if (pos & 1)
          it = *s.rbegin(), a--;
        else
          it = *s.begin(), b--;
        f = 1;
        a += (pos == 1);
      }
      ans[pos++] = it;
      s.erase(it);
    }
    if (aa == bb) f = 0;
    if (f == 0) {
      while (!s.empty()) {
        ans[pos++] = *s.rbegin();
        s.erase(*s.rbegin());
      }
    } else {
      while (!s.empty()) {
        ans[pos++] = *s.begin();
        s.erase(*s.begin());
      }
    }
    bool bad = (a > 0 || b > 0);
    a = aa, b = bb;
    for (int i = 2; i < n; i++) {
      a -= (ans[i] > ans[i - 1] && ans[i] > ans[i + 1]);
      b -= (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]);
    }
    bad |= (a != 0 | b != 0);
    if (bad) {
      cout << "-1";
      cout << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
