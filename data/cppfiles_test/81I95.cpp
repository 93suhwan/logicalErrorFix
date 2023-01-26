#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
namespace myrand {
mt19937 mt(chrono::system_clock::now().time_since_epoch() /
           chrono::microseconds(1));
ll Int(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(mt); }
}  // namespace myrand
using namespace myrand;
auto start_time = chrono::system_clock::now();
ld get_time() {
  auto Now = chrono::system_clock::now();
  return (chrono::duration_cast<chrono::nanoseconds>(Now - start_time).count() *
          1e-9);
}
const ld Time = 1.8;
const int N = 5e5 + 10;
struct segment_tree {
  int it[N * 4], lazy[N * 4], n, u, v, x;
  void init(int len) {
    n = len;
    for (int i = 1; i <= n * 4 + 10; ++i) it[i] = lazy[i] = 0;
  }
  int combine(int obj1, int obj2) { return max(obj1, obj2); }
  void apply(int id, int val) {
    it[id] += val;
    lazy[id] += val;
  }
  void push(int id) {
    apply(id << 1, lazy[id]);
    apply((id << 1) | 1, lazy[id]);
    lazy[id] = 0;
  }
  void update(int id, int l, int r) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
      apply(id, x);
      return;
    }
    int mid = (l + r) >> 1;
    push(id);
    update(id << 1, l, mid);
    update((id << 1) | 1, mid + 1, r);
    it[id] = combine(it[id << 1], it[(id << 1) | 1]);
  }
  int get(int id, int l, int r) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return it[id];
    int mid = (l + r) >> 1;
    push(id);
    return combine(get(id << 1, l, mid), get((id << 1) | 1, mid + 1, r));
  }
  void Update(int l, int r, int val) {
    u = l;
    v = r;
    x = val;
    update(1, 1, n);
  }
  int Get(int l, int r) {
    u = l;
    v = r;
    if (l > r) return 0;
    return get(1, 1, n);
  }
} seg;
int n, d, m;
pii a[N];
vi val;
int cal() {
  seg.init(m);
  for (int i = 1; i <= n; ++i) {
    int pos = upper_bound(val.begin(), val.end(), a[i].second) - val.begin();
    if (pos == 0) continue;
    int mid = lower_bound(val.begin(), val.end(), a[i].first) - val.begin() + 1;
    if (mid < pos) seg.Update(mid + 1, pos, 1);
    int cur = seg.Get(mid, mid);
    int nw = seg.Get(1, min(pos, mid)) + 1;
    if (nw > cur) seg.Update(mid, mid, nw - cur);
  }
  return seg.it[1];
}
bool cmp(pii p1, pii p2) {
  return make_pair(p1.second, p1.first) < make_pair(p2.second, p2.first);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> d;
  val.emplace_back(d);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].second >> a[i].first;
    if (a[i].first > d)
      val.emplace_back(a[i].first);
    else
      a[i].first = d;
  }
  sort(val.begin(), val.end());
  val.resize(unique(val.begin(), val.end()) - val.begin());
  m = val.size();
  sort(a + 1, a + n + 1);
  int res = cal();
  sort(a + 1, a + n + 1, cmp);
  res = max(res, cal());
  while (get_time() < Time) {
    shuffle(a + 1, a + n + 1, mt);
    res = max(res, cal());
  }
  cout << res;
  return 0;
}
