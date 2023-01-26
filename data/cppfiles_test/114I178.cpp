#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
const int inf = 1e9 + 7;
map<vector<int>, int> mp, mem;
vector<int> v[20], cur, ans;
int n, sz, x, Q, mx;
int cal(vector<int> now) {
  int res = 0;
  for (int i = 0; i < n; i++) res += v[i][now[i]];
  return res;
}
void f(vector<int> now) {
  if (!mp.count(now)) {
    if (cal(now) > mx) mx = cal(now), ans = now;
    return;
  }
  if (mem[now] || cal(now) < mx) return;
  mem[now] = 1;
  vector<int> tmp = now;
  for (int i = 0; i < n; i++) {
    if (i) tmp[i - 1]++;
    tmp[i]--;
    f(tmp);
  }
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
  f(cur);
  for (auto i : ans) cout << i + 1 << " ";
}
