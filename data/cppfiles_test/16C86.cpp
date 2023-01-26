#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> s, st;
set<pair<int, int>>::iterator it;
struct point {
  int x, y;
};
point ans[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, i, n, a, one, two, onek, twok, k;
  pair<int, int> p1, p2;
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
      p1 = *it;
      p1.first--;
      onek = p1.second;
      it = prev(it);
      p2 = *it;
      p2.first--;
      twok = p2.second;
      s.erase(next(it));
      s.erase(it);
      if (p1.first) s.insert(p1);
      if (p2.first) s.insert(p2);
      ans[k].x = onek;
      ans[k].y = twok;
      k++;
    }
    cout << k << endl;
    if (k)
      for (i = 0; i < k; i++) cout << ans[i].x << ' ' << ans[i].y << endl;
  }
  return 0;
};
