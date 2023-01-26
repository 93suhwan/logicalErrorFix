#include <bits/stdc++.h>
using namespace std;
std::pair<long long int, long long int> operator+(
    const std::pair<long long int, long long int>& x,
    const std::pair<long long int, long long int>& y) {
  return std::make_pair(x.first + y.first, x.second + y.second);
}
const int nax = 3e5 + 5;
int t[nax][18], a[nax];
void build(int n) {
  for (int i = 1; i <= n; ++i) t[i][0] = a[i];
  for (int k = 1; k < 18; ++k) {
    for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
      t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
    }
  }
}
int query(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return min(t[l][k], t[r - (1 << k) + 1][k]);
}
int n, q, k;
const int roz = (1 << 20);
long long int tree[roz];
pair<long long, long long> lazy[roz];
bool mark[roz];
int sz[roz];
long long int ary(long long int lo, long long int prog, long long int cnt) {
  return (lo + (lo + (cnt - 1) * prog)) * cnt / 2;
}
void push(long long int v) {
  if (mark[v]) {
    lazy[v * 2] = lazy[v * 2] + lazy[v];
    lazy[v * 2 + 1] = lazy[v * 2 + 1] + lazy[v];
    lazy[v * 2 + 1].first += lazy[v].second * sz[v * 2];
    mark[v * 2] = mark[v * 2 + 1] = true;
    tree[v * 2] += ary(lazy[v].first, lazy[v].second, sz[v * 2]);
    tree[v * 2 + 1] += ary(lazy[v].first + lazy[v].second * sz[v * 2],
                           lazy[v].second, sz[v * 2 + 1]);
    mark[v] = false;
    lazy[v] = make_pair(0, 0);
  }
}
void upd(int lo, int hi, int u, int a, int b, pair<long long, long long> val) {
  if (lo == a && b == hi) {
    lazy[u] = lazy[u] + val;
    tree[u] += ary(val.first, val.second, hi - lo);
    mark[u] = true;
    return;
  }
  if (b <= a) return;
  push(u);
  int mid = (lo + hi) / 2;
  upd(lo, mid, u * 2, a, min(b, mid), val);
  pair<long long, long long> go =
      make_pair(val.first + val.second * max(0, mid - a), val.second);
  upd(mid, hi, u * 2 + 1, max(a, mid), b, go);
  tree[u] = tree[u * 2] + tree[u * 2 + 1];
}
long long int ask(int lo, int hi, int u, int a, int b) {
  if (lo == a && b == hi) {
    return tree[u];
  }
  if (b <= a) return 0;
  push(u);
  int mid = (lo + hi) / 2;
  long long int L = ask(lo, mid, u * 2, a, min(b, mid));
  long long int R = ask(mid, hi, u * 2 + 1, max(a, mid), b);
  return L + R;
}
void ini() {
  for (int i = roz / 2; i < roz; i++) sz[i] = 1;
  for (int i = roz / 2 - 1; i >= 1; i--) sz[i] = sz[i * 2] + sz[i * 2 + 1];
}
vector<pair<int, int> > que[nax];
long long int ans[nax];
void solve() {
  cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(n);
  ini();
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    int ent = l % k;
    if (r % k < ent) {
      r -= (r % k + 1);
    }
    if (r % k >= ent) r -= (r % k - ent);
    que[l].push_back(make_pair(r, i));
  }
  for (int mod = 0; mod < k; mod++) {
    int last = n;
    if (last % k < mod) {
      last -= (last % k + 1);
    }
    last -= (last % k - mod);
    int cur = last;
    stack<pair<long long, long long> > alive;
    int mappedIndex = last / k;
    int bound = mappedIndex;
    while (cur >= 1) {
      int valueForNextIntervals = query(cur, min(n, cur + k));
      if (cur + k > n) valueForNextIntervals = 2e9;
      int offsetGone = 0;
      while (alive.size() && alive.top().first >= valueForNextIntervals) {
        auto akt = alive.top();
        alive.pop();
        int len = akt.second;
        upd(0, roz / 2, 1, mappedIndex + offsetGone + 1,
            mappedIndex + offsetGone + len + 1,
            make_pair(-akt.first, -akt.first));
        upd(0, roz / 2, 1, mappedIndex + offsetGone + len + 1, bound + 1,
            make_pair(-akt.first * len, 0));
        offsetGone += len;
      }
      if (offsetGone) alive.push(make_pair(valueForNextIntervals, offsetGone));
      int val2 = a[cur];
      alive.push(make_pair(val2, 1));
      upd(0, roz / 2, 1, mappedIndex, bound + 1, make_pair(val2, 0));
      upd(0, roz / 2, 1, mappedIndex + 1, mappedIndex + offsetGone + 1,
          make_pair(valueForNextIntervals, valueForNextIntervals));
      upd(0, roz / 2, 1, mappedIndex + offsetGone + 1, bound + 1,
          make_pair((long long int)valueForNextIntervals * offsetGone, 0LL));
      for (pair<int, int> q : que[cur]) {
        int to = q.first;
        int id = q.second;
        long long int ac = ask(0, roz / 2, 1, to / k, to / k + 1);
        ans[id] = ac;
      }
      mappedIndex -= 1;
      cur -= k;
    }
    int offsetGone = 0;
    while (alive.size()) {
      auto akt = alive.top();
      alive.pop();
      int len = akt.second;
      upd(0, roz / 2, 1, mappedIndex + offsetGone + 1,
          mappedIndex + offsetGone + len + 1,
          make_pair(-akt.first, -akt.first));
      upd(0, roz / 2, 1, mappedIndex + offsetGone + len + 1, bound + 1,
          make_pair(-akt.first * len, 0));
      offsetGone += len;
    }
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  while (tt--) solve();
  return 0;
}
