#include <bits/stdc++.h>
using namespace std;
void dbg() { cout << "DEBUG\n"; }
const int INF = 1e9;
const long long LINF = 1e18;
const long long mod = 1e9 + 7;
const int maxn = 100000;
struct Node {
  int val;
} seg[maxn << 2];
void pushup(int cur) {
  seg[cur].val = seg[cur << 1].val + seg[cur << 1 | 1].val;
  return;
}
void init(int cur, int l, int r) {
  if (l + 1 == r) {
    seg[cur].val = 0;
    return;
  }
  int mid = (l + r) >> 1;
  init(cur << 1, l, mid);
  init(cur << 1 | 1, mid, r);
  pushup(cur);
  return;
}
void update(int cur, int l, int r, int pos, int data) {
  if (l + 1 == r) {
    seg[cur].val += data;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos < mid)
    update(cur << 1, l, mid, pos, data);
  else
    update(cur << 1 | 1, mid, r, pos, data);
  pushup(cur);
  return;
}
int query(int cur, int l, int r, int x, int y) {
  if (l >= y || r <= x) return 0;
  if (l >= x && r <= y) return seg[cur].val;
  int mid = (l + r) >> 1;
  return query(cur << 1, l, mid, x, y) + query(cur << 1 | 1, mid, r, x, y);
}
void solve() {
  int m, n;
  cin >> m >> n;
  vector<int> arr(m * n);
  for (auto &x : arr) cin >> x;
  map<int, int> cnt;
  for (auto &x : arr) cnt[x]++;
  unordered_map<int, queue<int>> index;
  vector<bool> vis(n * m, false);
  int pos = 0, l = 1;
  for (auto &x : cnt) {
    int cur = x.first, times = x.second;
    while (times) {
      if (l * n - pos <= times) {
        times -= l * n - pos;
        vis[l * n - 1] = true;
        index[cur].push(l * n - 1);
        pos = l * n;
        l++;
      } else {
        pos += times;
        vis[pos - 1] = true;
        index[cur].push(pos - 1);
        times = 0;
      }
    }
  }
  vector<int> res(m * n);
  for (int i = 0; i < m * n; i++) {
    int cur = index[arr[i]].front();
    res[i] = cur;
    cur--;
    if (cur < 0 || vis[cur])
      index[arr[i]].pop();
    else
      index[arr[i]].front() -= 1;
  }
  int ans = 0;
  init(1, 0, n * m);
  for (int i = 0; i < n * m; i++) {
    int layer = res[i] / n;
    ans += query(1, 0, n * m, layer * n, res[i] + 1);
    update(1, 0, n * m, res[i], 1);
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
  return 0;
}
