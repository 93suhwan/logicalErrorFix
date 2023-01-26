#include <bits/stdc++.h>
using namespace std;
struct node {
  long long sum;
  node() { sum = INT_MAX; }
};
class segte {
 public:
  long long n{};
  vector<node> tree;
  vector<long long> a;
  node neutral;
  void init(long long N) {
    n = N;
    tree.resize(4 * n + 1);
    a.assign(n, INT_MAX);
  }
  void put(vector<long long> &val) { a = val; }
  void merge(node &curr, node &left, node &right) {
    curr.sum = min(left.sum, right.sum);
  }
  void single(node &curr, long long idx) { curr.sum = a[idx]; }
  void build(long long index, long long ss, long long se) {
    if (ss == se) {
      single(tree[index], ss);
      return;
    }
    long long mid = (ss + se) / 2;
    build(2 * index, ss, mid);
    build(2 * index + 1, mid + 1, se);
    merge(tree[index], tree[2 * index], tree[2 * index + 1]);
  }
  void build() { build(1, 0, n - 1); }
  node query(long long index, long long ss, long long se, long long qs,
             long long qe) {
    if (qs > se || qe < ss) return neutral;
    if (qs <= ss && qe >= se) return tree[index];
    long long mid = (ss + se) / 2;
    node left = query(2 * index, ss, mid, qs, qe);
    node right = query(2 * index + 1, mid + 1, se, qs, qe);
    node mer;
    merge(mer, left, right);
    return mer;
  }
  node query(long long l, long long r) { return query(1, 0, n - 1, l, r); }
  void update(long long index, long long idx, long long ss, long long se) {
    if (idx < ss || idx > se) return;
    if (ss == se) {
      single(tree[index], ss);
      return;
    }
    long long mid = (ss + se) / 2;
    update(2 * index, idx, ss, mid);
    update(2 * index + 1, idx, mid + 1, se);
    merge(tree[index], tree[2 * index], tree[2 * index + 1]);
  }
  void update(long long idx) { update(1, idx, 0, n - 1); }
};
void solve() {
  long long n;
  cin >> n;
  long long a[n + 1], b[n + 1], rb[n + 1];
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(rb, -1, sizeof rb);
  b[0] = 0;
  rb[0] = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] += i;
    rb[b[i]] = i;
  }
  segte s;
  s.init(n + 5);
  for (long long i = 1; i <= n; i++) {
    s.a[i] = i - a[i];
    s.update(i);
  }
  bool vis[n + 1];
  long long val[n + 1];
  memset(val, -1, sizeof val);
  memset(vis, 0, sizeof vis);
  vis[0] = true;
  val[0] = 0;
  vector<long long> check;
  check.push_back(0);
  while (!check.empty()) {
    vector<long long> ncheck;
    for (auto &c : check) {
      if (s.query(c, n).sum > c) continue;
      long long idx = c;
      while (true) {
        long long l = idx;
        if (s.query(l, l).sum <= c) {
          idx = l + 1;
          long long nidx = rb[l];
          if (nidx != -1 && !vis[nidx]) {
            ncheck.push_back(nidx);
            vis[nidx] = true;
          }
          val[l] = b[c];
          s.a[l] = INT_MAX;
          s.update(l);
        } else {
          long long r = n + 1;
          while (l + 1 < r) {
            long long m = (l + r) / 2;
            if (s.query(l, m).sum <= c) {
              r = m;
            } else {
              l = m;
            }
          }
          if (r == n + 1) break;
          idx = r;
          long long nidx = rb[r];
          if (nidx != -1 && !vis[nidx]) {
            ncheck.push_back(nidx);
            vis[nidx] = true;
          }
          val[r] = b[c];
          s.a[r] = INT_MAX;
          s.update(r);
        }
      }
    }
    check = ncheck;
  }
  if (val[n] == -1) {
    cout << -1 << "\n";
  } else {
    vector<long long> ans;
    while (n != 0) {
      n = val[n];
      ans.push_back(rb[n]);
    }
    cout << ans.size() << "\n";
    for (auto &c : ans) {
      cout << c << " ";
    }
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
