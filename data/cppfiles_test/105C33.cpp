#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, INF = 0x3f3f3f3f;
int a[maxn], b[maxn], m[maxn], ans[maxn];
struct Node {
  int l, r, id;
  bool operator<(const Node &t) const {
    if (r != t.r) return r < t.r;
    return l < t.l;
  }
};
map<int, vector<Node> > mp;
int solve(vector<Node> &v) {
  int res = 0;
  sort(v.begin(), v.end());
  for (int l = 0, r = 0; l < int(v.size()); l = r) {
    auto [x, y, id] = v[l];
    res++;
    while (r < int(v.size())) {
      auto [_x, _y, _id] = v[r];
      if (_x > y) break;
      r++;
      ans[_id] = y;
    }
  }
  return res;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    mp.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i] >> m[i];
      mp[a[i] + b[i] - m[i]].push_back(
          {max(0, a[i] - m[i]), a[i] + min(0, b[i] - m[i]), i});
    }
    int res = 0;
    for (auto &[x, y] : mp) res += solve(y);
    cout << res << '\n';
    for (int i = 1; i <= n; i++)
      cout << a[i] - ans[i] << ' ' << m[i] + ans[i] - a[i] << '\n';
  }
}
