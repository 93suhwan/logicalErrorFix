#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> s, st;
set<pair<int, int>>::iterator it, it1;
struct point {
  int x, y;
};
point ans[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, i, n, a, one, two, onek, twok, k;
  pair<int, int> p;
  cin >> t;
  while (t--) {
    s = st;
    k = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> a;
      if (a) s.insert({a, i});
    }
    while (s.size() > 1) {
      it = s.end();
      it = prev(it);
      p = *it;
      one = p.first;
      onek = p.second;
      it = prev(it);
      p = *it;
      two = p.first;
      twok = p.second;
      it1 = next(it);
      s.erase(it1);
      s.erase(it);
      for (i = 0; i < two; i++) {
        ans[k].x = onek;
        ans[k].y = twok;
        k++;
      }
      if (one - two) s.insert({one - two, onek});
    }
    cout << k << endl;
    if (k)
      for (i = 0; i < k; i++) cout << ans[i].x << ' ' << ans[i].y << endl;
  }
  return 0;
};
