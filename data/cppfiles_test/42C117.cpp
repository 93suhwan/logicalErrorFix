#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int n, m, seg[N << 2], lazy[N << 2];
;
vector<pair<int, pair<int, int>>> v;
void push(int i, int l, int r) {
  if (!lazy[i]) return;
  seg[i] += lazy[i];
  if (l != r) lazy[i << 1] += lazy[i], lazy[i << 1 | 1] += lazy[i];
  lazy[i] = 0;
}
void update(int i, int l, int r, int a, int b, long long int v) {
  push(i, l, r);
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    lazy[i] += v;
    return push(i, l, r);
  }
  int mid = (l + r) >> 1;
  update(i << 1, l, mid, a, b, v);
  update(i << 1 | 1, mid + 1, r, a, b, v);
  seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
}
int get(int i, int l, int r, int a, int b) {
  push(i, l, r);
  if (l > b || r < a) return 1e9;
  if (l >= a && r <= b) return seg[i];
  int mid = (l + r) >> 1;
  int ret = get(i << 1, l, mid, a, b);
  ret = min(ret, get(i << 1 | 1, mid + 1, r, a, b));
  seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    v.push_back({w, {x, y}});
  }
  sort(v.begin(), v.end());
  int j = 0;
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    while (j < n && get(1, 1, m - 1, 1, m - 1) == 0) {
      update(1, 1, m - 1, v[j].second.first, v[j].second.second - 1, 1);
      j++;
    }
    if (get(1, 1, m - 1, 1, m - 1) != 0) {
      ans = min(ans, v[j - 1].first - v[i].first);
    }
    update(1, 1, m - 1, v[i].second.first, v[i].second.second - 1, -1);
  }
  cout << ans << '\n';
}
