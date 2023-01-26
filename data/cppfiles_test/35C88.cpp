#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e6 + 100;
struct fenwick {
  int min_sum, max_sum, max_pos;
  vector<int> min_pos;
  void init(int _min_sum, int _max_sum, int _max_pos) {
    min_sum = _min_sum;
    max_sum = _max_sum;
    max_pos = _max_pos;
    min_pos.assign(max_sum - min_sum + 1, max_pos);
  }
  void add_sum(int s, int pos) {
    assert(min_sum <= s && s <= max_sum);
    s -= min_sum;
    while (s < ((int)(min_pos).size())) {
      min_pos[s] = min(min_pos[s], pos);
      s = (s | (s + 1));
    }
  }
  int get_min_pos(int s) {
    s -= min_sum;
    assert(s < ((int)(min_pos).size()));
    int res = max_pos;
    while (s >= 0) {
      res = min(res, min_pos[s]);
      s = (s & (s + 1)) - 1;
    }
    return res;
  }
};
int maxv;
fenwick f;
char b[N];
int p[N], s[N], cnt[N];
int min_bad_pos[4 * N];
vector<int> add[N], del[N];
vector<pair<int, int> > dels[N];
void init() {
  vector<int> lst;
  for (int i = 2; i < N; ++i) {
    if (p[i] == 0) {
      p[i] = i;
      lst.push_back(i);
    }
    for (int j = 0; j < ((int)(lst).size()) && lst[j] <= p[i] && lst[j] * i < N;
         ++j) {
      p[lst[j] * i] = lst[j];
    }
  }
}
void add_seg(int l, int r, int bad_from) {
  assert(l <= r);
  assert(r <= bad_from);
  add[l].push_back(bad_from);
  del[r].push_back(bad_from);
}
void add_bad_pos(int pos) {
  ++cnt[pos];
  if (cnt[pos] == 1) {
    min_bad_pos[pos + maxv] = pos;
    pos += maxv;
    while (pos > 1) {
      pos /= 2;
      min_bad_pos[pos] = min(min_bad_pos[pos * 2], min_bad_pos[pos * 2 + 1]);
    }
  }
}
void del_bad_pos(int pos, int max_pos) {
  --cnt[pos];
  assert(cnt[pos] >= 0);
  if (cnt[pos] == 0) {
    min_bad_pos[pos + maxv] = max_pos;
    pos += maxv;
    while (pos > 1) {
      pos /= 2;
      min_bad_pos[pos] = min(min_bad_pos[pos * 2], min_bad_pos[pos * 2 + 1]);
    }
  }
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    while (x > 1) {
      int y = p[x], cnt = 0;
      while (x % y == 0) {
        x /= y;
        ++cnt;
      }
      dels[y].push_back(make_pair(i, cnt));
    }
  }
  scanf("%s", b);
  for (int d = 2; d < N; ++d) {
    if (((int)(dels[d]).size()) == 0) {
      continue;
    }
    int min_sum = 0, max_sum = 0;
    for (int i = 0; i < ((int)(dels[d]).size()); ++i) {
      s[i] = (i > 0 ? s[i - 1] : 0) +
             (b[dels[d][i].first] == '*' ? 1 : -1) * dels[d][i].second;
      min_sum = min(min_sum, s[i]);
      max_sum = max(max_sum, s[i]);
    }
    f.init(min_sum, max_sum, n);
    for (int i = ((int)(dels[d]).size()) - 1; i >= 0; --i) {
      f.add_sum(s[i], dels[d][i].first);
      add_seg((i > 0 ? dels[d][i - 1].first + 1 : 0), dels[d][i].first,
              f.get_min_pos((i > 0 ? s[i - 1] : 0) - 1));
    }
  }
  maxv = 1;
  while (maxv < n + 1) {
    maxv *= 2;
  }
  for (int i = 1; i < 2 * maxv; ++i) {
    min_bad_pos[i] = n;
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int bad_pos : add[i]) {
      add_bad_pos(bad_pos);
    }
    assert(min_bad_pos[1] >= i);
    ans += min_bad_pos[1] - i;
    for (int bad_pos : del[i]) {
      del_bad_pos(bad_pos, n);
    }
  }
  printf("%lld\n", ans);
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
