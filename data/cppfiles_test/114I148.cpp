#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
const int inf = 1e9 + 7;
vector<int> v[20], root;
int n, sz, x, Q, tot, ban;
struct ItemSet {
  vector<int> pos;
  int tot, cur;
};
map<vector<int>, int> mp;
bool operator<(ItemSet a, ItemSet b) {
  return a.tot < b.tot || a.tot == b.tot && a.cur < b.cur ||
         a.tot == b.tot && a.cur == b.cur && a.pos < b.pos;
}
multiset<ItemSet> s;
void out() {
  for (auto i : s) cout << i.tot << " ";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  if (fopen("tst"
            ".inp",
            "r")) {
    freopen(
        "tst"
        ".inp",
        "r", stdin);
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> sz;
    root.push_back(sz - 1);
    for (int j = 1; j <= sz; j++) cin >> x, v[i].push_back(x);
    tot += v[i].back();
  }
  s.insert({root, tot, 1});
  cin >> Q;
  ban = Q;
  while (Q--) {
    vector<int> tmp;
    for (int i = 1; i <= n; i++) cin >> x, x--, tmp.push_back(x);
    mp[tmp] = 1;
  }
  while (!s.empty()) {
    ItemSet t = *s.rbegin();
    s.erase(prev(s.end()));
    if (!mp.count(t.pos)) {
      for (auto i : t.pos) cout << i + 1 << " ";
      exit(0);
    }
    for (int i = t.cur; i <= n; i++) {
      int now = t.pos[i - 1];
      vector<int> tmp = t.pos;
      tmp[i - 1]--;
      if (now > 0) s.insert({tmp, tot - v[i][now] + v[i][now - 1], i});
    }
    while (s.size() > ban + 2) s.erase(s.begin());
  }
}
