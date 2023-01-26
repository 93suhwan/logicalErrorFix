#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int main() {
  int q;
  cin >> q;
  vector<P> v(q);
  for (int qi = 0; qi < q; qi++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      v[qi] = {x, 0};
    } else {
      int x, y;
      cin >> x >> y;
      v[qi] = {-x, y};
    }
  }
  reverse(v.begin(), v.end());
  map<int, int> to;
  vector<int> ans;
  for (auto now : v) {
    if (now.first >= 0) {
      if (to.count(now.first)) {
        now.first = to[now.first];
      }
      ans.push_back(now.first);
    } else {
      now.first *= -1;
      if (to.count(now.second)) {
        to[now.first] = to[now.second];
      } else {
        to[now.first] = now.second;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans[0];
  for (int i = 1; i < (int)ans.size(); i++) {
    cout << " " << ans[i];
  }
  cout << endl;
  return 0;
}
