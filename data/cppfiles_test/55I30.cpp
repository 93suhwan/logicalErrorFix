#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, opt, l, r, v, ans;
int a[N], minn[N * 35], tag[N * 35], lson[N * 35], rson[N * 35], cnt = 1;
inline void pushdown(int k) {
  if (~tag[k]) {
    minn[lson[k]] = minn[rson[k]] = tag[k];
    tag[lson[k]] = tag[rson[k]] = tag[k];
    tag[k] = -1;
  }
}
void change(int k, int l, int r, int qx, int qy, int v) {
  if (qx <= l && r <= qy) {
    minn[k] = v;
    tag[k] = v;
    return;
  }
  if (!lson[k]) lson[k] = ++cnt;
  if (!rson[k]) rson[k] = ++cnt;
  pushdown(k);
  int mid = l + r >> 1;
  if (qx <= mid) change(lson[k], l, mid, qx, qy, v);
  if (mid < qy) change(rson[k], mid + 1, r, qx, qy, v);
  minn[k] = max(minn[lson[k]], minn[rson[k]]);
}
int query(int k, int l, int r, int qx, int qy) {
  if (qx <= l && r <= qy) return minn[k];
  if (!lson[k]) lson[k] = ++cnt;
  if (!rson[k]) rson[k] = ++cnt;
  pushdown(k);
  int mid = l + r >> 1;
  int ans = 0;
  if (qx <= mid) ans = max(ans, query(lson[k], l, mid, qx, qy));
  if (mid < qy) ans = max(ans, query(rson[k], mid + 1, r, qx, qy));
  return ans;
}
vector<pair<int, int>> q[300500];
map<int, int> mp;
int nxt[300500], i, j, f[300500], mx, res[300500];
int main() {
  memset(tag, -1, sizeof(tag));
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    q[x].push_back({y, z});
  }
  for (i = n; i >= 1; i--) {
    int sb = 0;
    for (auto [x, y] : q[i]) {
      sb = max(sb, query(1, 1, 1000000000, x, y));
    }
    nxt[i] = mp[sb];
    sb++;
    for (auto [x, y] : q[i]) {
      change(1, 1, 1000000000, x, y, sb);
    }
    mp[sb] = i;
    f[i] = sb;
    mx = max(mx, sb);
  }
  for (i = 1; i <= n; i++) {
    if (f[i] == mx) {
      j = i;
      while (j) {
        res[j] = 1;
        j = nxt[j];
      }
      break;
    }
  }
  printf("%d\n", n - mx);
  for (i = 1; i <= n; i++) {
    if (!res[i]) {
      printf("%d ", i);
    }
  }
}
