#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e6;
const long long MOD = 1e9 + 7;
using namespace std;
int q, x, y, z, n, m, a[KL], b[KL], c[KL];
string t;
vector<int> vec;
int dp[KL], pr[KL];
int seg[2 * KL], idx[2 * KL];
void build(int cur = 1, int st = 1, int en = n) {
  if (st == en) {
    seg[cur] = c[st];
    idx[cur] = st;
  } else {
    int mid = (st + en) / 2;
    build(2 * cur, st, mid);
    build(2 * cur + 1, mid + 1, en);
    seg[cur] = min(seg[2 * cur], seg[2 * cur + 1]);
    if (seg[2 * cur] <= seg[2 * cur + 1])
      idx[cur] = idx[2 * cur];
    else
      idx[cur] = idx[2 * cur + 1];
  }
}
pair<int, int> query(int l, int r, int cur = 1, int st = 1, int en = n) {
  if (r < st || en < l) return {1e9, n};
  if (l <= st && en <= r) return {seg[cur], idx[cur]};
  int mid = (st + en) / 2;
  pair<int, int> val1 = query(l, r, 2 * cur, st, mid);
  pair<int, int> val2 = query(l, r, 2 * cur + 1, mid + 1, en);
  pair<int, int> ret;
  ret.first = min(val1.first, val2.first);
  if (val1.first <= val2.first)
    ret.second = val1.second;
  else
    ret.second = val2.second;
  return ret;
}
int main() {
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] < i) cnt++;
    a[i] = i - a[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    x = b[i] + i;
    c[i] = a[x];
  }
  if (cnt == n) {
    printf("-1\n");
    return 0;
  }
  build();
  bool ok = true;
  vector<int> path;
  pair<int, int> cur = {n, n};
  cnt = 0;
  while (cur.first != 0) {
    pair<int, int> nw = query(cur.first, n);
    if (nw.first == cur.first) {
      ok = false;
      break;
    }
    cnt++;
    cur = nw;
    path.push_back(cur.second);
  }
  path.push_back(0);
  if (!ok) {
    printf("-1\n");
  } else {
    printf("%d\n", cnt);
    for (int i = 1; i < path.size(); i++) {
      printf("%d ", path[i]);
    }
    printf("\n");
  }
  return 0;
}
