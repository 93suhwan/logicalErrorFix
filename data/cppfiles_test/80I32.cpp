#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int d4x[4] = {1, 0, -1, 0};
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long oo = 1e18;
const long long maxN = 1e6;
void maximize(int &a, int b) { a = max(a, b); }
void minimize(int &a, int b) { a = min(a, b); }
struct FenwickTree {
  int n;
  vector<int> Node;
  FenwickTree(int _n = 0) {
    n = _n;
    Node.resize(n + 5);
  }
  void update(int x, int val) {
    for (x; x <= n; x += x & (-x)) Node[x] += val;
  }
  int get(int x) {
    int ans = 0;
    for (x; x > 0; x -= x & (-x)) ans += Node[x];
    return ans;
  }
};
struct SegemntTree {
  int n;
  vector<int> Node;
  vector<int> Lazy;
  SegemntTree(int _n = 0) {
    n = _n;
    Node.resize(4 * n + 7);
    Lazy.resize(4 * n + 7);
    for (int i = 1; i <= 4 * n; i++) Node[i] = Lazy[i] = 0;
  }

 private:
  void Down(int id) {
    if (!Lazy[id]) return;
    for (int i = 2 * id; i <= 2 * id + 1; i++) {
      Node[i] += Lazy[id];
      Lazy[i] += Lazy[id];
    }
    Lazy[id] = 0;
  }
  void Update(int L, int R, int lo, int hi, int id, int val) {
    if (R < lo || L > hi) return;
    if (lo <= L && R <= hi) {
      Node[id] += val;
      Lazy[id] += val;
      return;
    }
    int mid = (L + R) >> 1;
    Down(id);
    Update(L, mid, lo, hi, id << 1, val);
    Update(mid + 1, R, lo, hi, id << 1 | 1, val);
    Node[id] = max(Node[id << 1], Node[id << 1 | 1]);
  }

 public:
  void update(int L, int R, int val) { Update(1, n, L, R, 1, val); }
};
const int N = 2e6 + 10;
int a[N], b[N];
pair<int, int> c[N];
vector<int> pos[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n + m; i++) pos[i].clear();
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c[i] = make_pair(a[i], i);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    c[i + n] = make_pair(b[i], i + n);
  }
  sort(c + 1, c + 1 + n + m);
  int cnt = 0;
  for (int i = 1; i <= n + m; i++) {
    if (c[i].first != c[i - 1].first) ++cnt;
    if (c[i].second > n)
      b[c[i].second - n] = cnt;
    else
      a[c[i].second] = cnt;
  }
  sort(b + 1, b + 1 + m);
  long long ans = 0;
  FenwickTree bit = FenwickTree(cnt);
  SegemntTree it = SegemntTree(n);
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    ans += i - 1 - bit.get(x);
    bit.update(x, 1);
    pos[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) it.update(i, n, -1);
  int lower = 0;
  for (int i = 1; i <= m; i++) {
    while (lower + 1 < b[i]) {
      ++lower;
      for (auto v : pos[lower]) {
        it.update(v, n, (lower == b[i - 1] ? 1 : 2));
      }
    }
    if (b[i] != b[i - 1])
      ;
    for (auto v : pos[b[i]]) {
      it.update(v, n, 1);
    }
    ans += bit.get(b[i] - 1) - max(0, it.Node[1]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1, ddd = 0;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
