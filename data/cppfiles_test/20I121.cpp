#include <bits/stdc++.h>
using namespace std;
inline int getint() {
  int n;
  scanf("%d", &n);
  return n;
}
vector<int> a[105];
vector<pair<int, int> > b;
int sg[100005], add[100005];
bool lazy[100005];
void push_down(int rt, int l, int r) {
  lazy[rt << 1] = lazy[rt << 1 | 1] = true;
  add[rt << 1] += add[rt];
  add[rt << 1 | 1] += add[rt];
  sg[rt << 1] += add[rt];
  sg[rt << 1 | 1] += add[rt];
  add[rt] = 0;
  lazy[rt] = false;
}
void push_up(int rt) { sg[rt] = max(sg[rt << 1], sg[rt << 1 | 1]); }
int get_max(int L, int R, int rt, int l, int r) {
  if (L <= l && r <= R) return sg[rt];
  if (lazy[rt]) push_down(rt, l, r);
  int ans = 0;
  int mid = (l + r) >> 1;
  if (L <= mid) ans = max(ans, get_max(L, R, rt << 1, l, mid));
  if (R > mid) ans = max(ans, get_max(L, R, rt << 1 | 1, mid + 1, r));
  return ans;
}
void add_one(int L, int R, int rt, int l, int r) {
  if (L <= l && r <= R) {
    lazy[rt] = true;
    add[rt] += 1;
    sg[rt] += 1;
    return;
  }
  if (lazy[rt]) push_down(rt, l, r);
  int mid = (l + r) >> 1;
  if (L <= mid) add_one(L, R, rt << 1, l, mid);
  if (R > mid) add_one(L, R, rt << 1 | 1, mid + 1, r);
  push_up(rt);
}
bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
  int len_x = x.second - x.first;
  int len_y = y.second - y.first;
  if (len_x == len_y) return x.first < y.first;
  return len_x < len_y;
}
bool used[105];
int record[10005];
vector<pair<int, int> > ans;
int main() {
  int n = getint(), K = getint();
  for (int i = 1; i <= n * K; i++) {
    int c = getint();
    record[i] = c;
    a[c].emplace_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      for (int k = j + 1; k < a[i].size(); k++) {
        b.emplace_back(pair<int, int>(a[i][j], a[i][k]));
      }
    }
  }
  sort(b.begin(), b.end(), cmp);
  int M = int(n + K - 2) / (K - 1);
  int cnt = n;
  ans.resize(n + 1);
  for (int i = 0; i < b.size(); i++) {
    if (cnt == 0) break;
    int col = record[b[i].first];
    if (used[col]) continue;
    if (get_max(b[i].first, b[i].second, 1, 1, n * K) < M) {
      ans[col] = pair<int, int>(b[i].first, b[i].second);
      cnt--;
      used[col] = true;
      add_one(b[i].first, b[i].second, 1, 1, n * K);
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
