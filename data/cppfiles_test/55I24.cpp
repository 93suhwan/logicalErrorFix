#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const int mxx = 300005;
vector<pair<int, int> > v[2 * mxx];
unordered_map<int, int> mp;
long long int Max[mxx];
long long int tree[4 * mxx];
void update(int l, int r, int L, int R, int n, int val) {
  if (l > R || r < L)
    return;
  else if (l >= L and r <= R) {
    tree[n] = val + 1;
    return;
  }
  tree[n] -= max(tree[n * 2], tree[n * 2 + 1]);
  update(l, (l + r) / 2, L, R, n * 2, val);
  update((l + r) / 2 + 1, r, L, R, n * 2 + 1, val);
  tree[n] += max(tree[n * 2], tree[n * 2 + 1]);
}
int go(int l, int r, int L, int R, int n, int val) {
  if (l > R || r < L)
    return 0;
  else if (l >= L and r <= R) {
    return tree[n] + val;
  }
  val += tree[n] - max(tree[n * 2], tree[n * 2 + 1]);
  int x = max(go(l, (l + r) / 2, L, R, n * 2, val),
              go((l + r) / 2 + 1, r, L, R, n * 2 + 1, val));
  return x;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> compress, del;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    compress.push_back(b);
    compress.push_back(c);
  }
  sort(compress.begin(), compress.end());
  int sum = 0;
  for (auto it : compress) {
    if (mp[it] == 0) mp[it] = ++sum;
  }
  int ans = 0;
  int p = 0;
  for (int i = n; i >= 1; i--) {
    int mx = 0;
    for (auto it : v[i]) {
      int x = mp[it.first];
      int y = mp[it.second];
      int fre = go(1, sum, x, y, 1, 0);
      mx = max(mx, fre);
    }
    for (auto it : v[i]) {
      int x = mp[it.first];
      int y = mp[it.second];
      update(1, sum, x, y, 1, mx);
    }
    Max[i] = mx + 1;
    if (ans < mx + 1) {
      ans = mx + 1;
      p = i;
    }
  }
  memset(tree, 0, sizeof(tree));
  for (int i = 1; i <= n; i++) {
    if (i < p) {
      del.push_back(i);
    } else if (i == p) {
      for (auto it : v[i]) {
        update(1, sum, mp[it.first], mp[it.second], 1, 1);
      }
    } else if (i > p) {
      if (Max[i] < ans - 1) {
        del.push_back(i);
        continue;
      }
      int mx = 0;
      for (auto it : v[i]) {
        int x = mp[it.first];
        int y = mp[it.second];
        int fre = go(1, sum, x, y, 1, 0);
        mx = max(mx, fre);
      }
      if (mx) {
        for (auto it : v[p]) {
          update(1, sum, mp[it.first], mp[it.second], 1, -1);
        }
        ans--;
        for (auto it : v[i]) {
          update(1, sum, mp[it.first], mp[it.second], 1, 1);
        }
        p = i;
      } else
        del.push_back(i);
    }
  }
  cout << del.size() << "\n";
  for (auto it : del) {
    cout << it << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t = 1;
  while (t--) solve();
}
