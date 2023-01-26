#include <bits/stdc++.h>
using namespace std;
void print(bool n) {
  if (n)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';
}
int n;
vector<int> a;
vector<int> seg;
void build(int id = 1, int l = 0, int r = n) {
  if (r - l == 1) {
    seg[id] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(2 * id, l, mid);
  build(2 * id + 1, mid, r);
  seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}
int query(int x, int y, int id = 1, int l = 0, int r = n) {
  if (l >= x && r <= y) {
    return seg[id];
  }
  if (l >= y || r <= x) {
    return 0;
  }
  int mid = (l + r) / 2;
  return max(query(x, y, 2 * id, l, mid), query(x, y, 2 * id + 1, mid, r));
}
void modify(int pos, int val, int id = 1, int l = 0, int r = n) {
  if (r - l == 1) {
    seg[id] = val;
    a[pos] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos < mid)
    modify(pos, val, 2 * id, l, mid);
  else
    modify(pos, val, 2 * id + 1, mid, r);
  seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  a.resize(n);
  seg.resize(4 * n + 1);
  int b[n];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    --b[i];
  }
  vector<vector<int>> mp(n);
  for (int i = 0; i < n; i++)
    if (i - b[i] >= 0 && b[i] < n) mp[b[i]].push_back(i - b[i]);
  for (const vector<int> &x : mp)
    for (auto it = x.rbegin(); it != x.rend(); ++it)
      modify(*it, query(0, *it + 1) + 1);
  cout << query(0, n);
  return 0;
}
