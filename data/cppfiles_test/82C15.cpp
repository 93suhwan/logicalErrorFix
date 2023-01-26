#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace std;
template <typename T1, typename T2>
ostream &operator<<(ostream &i, pair<T1, T2> j) {
  return i << j.first << ' ' << j.second;
}
template <typename T>
ostream &operator<<(ostream &i, vector<T> j) {
  i << '{' << j.size() << ':';
  for (T ii : j) i << ' ' << ii;
  return i << '}';
}
void Debug(bool _split) {}
template <typename T1, typename... T2>
void Debug(bool _split, T1 x, T2... args) {
  if (_split) cerr << ", ";
  cerr << x, Debug(true, args...);
}
template <typename T>
void Debuga(T *i, int n) {
  cerr << '[';
  for (int j = 0; j < n; ++j) cerr << i[j] << " ]"[j == n - 1];
  cerr << endl;
}
const int inf = 0x3f3f3f3f, lg = 20;
const long long mod = 1e9 + 7, INF = 0x3f3f3f3f3f3f3f3f;
struct seg {
  int l, r, mn, mx;
  long long s;
  seg *ch[2]{};
  seg(int _l, int _r) : l(_l), r(_r) {
    if (l < r - 1)
      ch[0] = new seg(l, l + r >> 1), ch[1] = new seg(l + r >> 1, r), pull();
    else
      s = mn = mx = inf;
  }
  void pull() {
    mn = ch[1]->mn;
    mx = ch[0]->mx;
    s = ch[0]->s + ch[1]->s;
  }
  void push() {
    if (mn == mx) {
      ch[0]->mn = ch[0]->mx = ch[1]->mn = ch[1]->mx = mn;
      ch[0]->s = 1ll * mn * (ch[0]->r - l);
      ch[1]->s = 1ll * mn * (r - ch[1]->l);
    }
  }
  void modify(int _l, int v) {
    if (v >= mx) return;
    if (_l <= l && v <= mn) {
      mn = mx = v;
      s = 1ll * v * (r - l);
      return;
    }
    push();
    if (_l < l + r >> 1) ch[0]->modify(_l, v);
    ch[1]->modify(_l, v);
    pull();
  }
  long long query(int _l, int _r) {
    if (_l <= l && r <= _r) return s;
    push();
    long long res = 0;
    if (_l < l + r >> 1) res += ch[0]->query(_l, _r);
    if (l + r >> 1 < _r) res += ch[1]->query(_l, _r);
    return res;
  }
};
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  vector<seg> rts;
  for (int i = 0; i < k; ++i) rts.emplace_back(0, n / k + 1);
  int a[n];
  for (int &i : a) cin >> i;
  vector<pair<int, int> > qs[n];
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    y = (y - x - 1) / k + 1;
    qs[x].emplace_back(y, i);
  }
  long long ans[q];
  deque<pair<int, int> > dq;
  for (int i = n - 1; ~i; --i) {
    if (i + k < n) {
      while (dq.front().second > i + k) dq.pop_front();
      rts[i % k].modify(i / k + 1, dq.front().first);
    }
    rts[i % k].modify(i / k, a[i]);
    while (!dq.empty() && a[i] <= dq.back().first) dq.pop_back();
    dq.emplace_back(a[i], i);
    for (pair<int, int> j : qs[i])
      ans[j.second] = rts[i % k].query(i / k, i / k + j.first);
  }
  for (long long i : ans) cout << i << '\n';
}
