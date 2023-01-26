#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
const int inf = 1e9 + 7;
map<vector<int>, int> mp;
vector<int> v[20], cur;
int n, sz, x, Q;
int Getmin() {
  int mn = inf, chosen = 0;
  for (int i = 0; i < n; i++) {
    if (cur[i] && mn > v[i][cur[i]] - v[i][cur[i] - 1])
      mn = v[i][cur[i]] - v[i][cur[i] - 1], chosen = i;
  }
  return chosen;
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
  for (int i = 0; i < n; i++) {
    cin >> sz;
    cur.push_back(sz - 1);
    while (sz--) cin >> x, v[i].push_back(x);
  }
  cin >> Q;
  while (Q--) {
    vector<int> tmp;
    for (int i = 1; i <= n; i++) cin >> x, tmp.push_back(x - 1);
    mp[tmp] = 1;
  }
  while (1) {
    if (!mp.count(cur)) {
      for (auto i : cur) cout << i + 1 << " ";
      return 0;
    }
    int pos = Getmin();
    cur[pos]--;
  }
}
