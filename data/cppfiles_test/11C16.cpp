#include <bits/stdc++.h>
using namespace std;
void print(bool n) {
  if (n)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';
}
long long n;
vector<long long> a;
vector<long long> seg;
void build(long long id = 1, long long l = 0, long long r = n) {
  if (r - l == 1) {
    seg[id] = a[l];
    return;
  }
  long long mid = (l + r) / 2;
  build(2 * id, l, mid);
  build(2 * id + 1, mid, r);
  seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}
long long query(long long x, long long y, long long id = 1, long long l = 0,
                long long r = n) {
  if (l >= x && r <= y) {
    return seg[id];
  }
  if (l >= y || r <= x) {
    return 0;
  }
  long long mid = (l + r) / 2;
  return max(query(x, y, 2 * id, l, mid), query(x, y, 2 * id + 1, mid, r));
}
void modify(long long pos, long long val, long long id = 1, long long l = 0,
            long long r = n) {
  if (r - l == 1) {
    seg[id] = val;
    a[pos] = val;
    return;
  }
  long long mid = (l + r) / 2;
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
  long long b[n];
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    --b[i];
  }
  vector<vector<long long>> mp(n);
  for (long long i = 0; i < n; i++)
    if (i - b[i] >= 0 && b[i] < n) mp[b[i]].push_back(i - b[i]);
  for (const vector<long long> &x : mp)
    for (auto it = x.rbegin(); it != x.rend(); ++it)
      modify(*it, query(0, *it + 1) + 1);
  cout << query(0, n);
  return 0;
}
