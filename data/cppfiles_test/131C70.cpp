#include <bits/stdc++.h>
using namespace std;
int n;
int get(int x) {
  int t = log2(x);
  if ((1 << t) < x) t++;
  return (1 << t) - x;
}
unordered_map<int, int> to, pos;
unordered_map<int, vector<pair<pair<int, int>, int> > > mp;
int a[200005];
pair<pair<int, int>, int> num[200005];
int len = 0;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int ans = 0, a1 = 0, a2 = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
  sort(a + 1, a + n + 1, greater<int>());
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    int cnt = 0;
    while (x) {
      int t = get(x);
      cnt++;
      mp[t].emplace_back(make_pair(make_pair(cnt, x), pos[a[i]]));
      to[x] = t;
      if (pos.count(t)) {
        if (cnt > ans) {
          ans = cnt;
          a1 = pos[a[i]];
          a2 = pos[t];
        }
      }
      x = t;
    }
  }
  for (auto u : mp) {
    len = 0;
    for (auto tu : u.second) {
      num[++len] = tu;
    }
    sort(num + 1, num + len + 1);
    pair<pair<int, int>, int> now = num[len];
    while (len && num[len].first.second == now.first.second) len--;
    if (len) {
      pair<pair<int, int>, int> p2 = num[len];
      if (now.first.first + p2.first.first > ans) {
        ans = now.first.first + p2.first.first;
        a1 = now.second;
        a2 = p2.second;
      }
    }
  }
  cout << a1 << ' ' << a2 << ' ' << ans;
  return 0;
}
