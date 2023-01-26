#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
using Graph = vector<vector<long long>>;
const int INF = 1000000007;
const long long MOD = 1000000007;
struct SegmentTree {
 private:
  int n;
  vector<int> node;

 public:
  SegmentTree(vector<int> v) {
    int sz = v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, INF);
    for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      node[i] = min(node[2 * i + 1], node[2 * i + 2]);
  }
  void update(int x, int val) {
    x += (n - 1);
    node[x] = val;
    while (x > 0) {
      x = (x - 1) / 2;
      node[x] = min(node[2 * x + 1], node[2 * x + 2]);
    }
  }
  int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return node[k];
    int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
    int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n + 1), b(n + 1);
  for (long long i = (0); i < (n); i++) cin >> a[i + 1];
  for (long long i = (0); i < (n); i++) cin >> b[i + 1];
  vector<int> v(n + 1, INF);
  v[n] = 0;
  vector<long long> memo(n + 1, -1);
  SegmentTree tree(v);
  map<long long, set<int>> mp;
  mp[0].insert(n);
  vector<long long> MEMO(n + 1);
  for (long long i = n; i >= 1; i--) {
    long long now = tree.getmin(0, i + 1);
    MEMO[i] = *mp[now].begin();
    long long pos = i + b[i];
    long long to = pos - a[pos];
    long long x = tree.getmin(to, to + 1);
    if (now + 1 < x) {
      tree.update(to, now + 1);
      memo[to] = i;
      mp[now + 1].insert(to);
    }
  }
  long long A = tree.getmin(0, 1);
  if (A >= MOD) {
    cout << -1 << endl;
    return 0;
  }
  cout << A << endl;
  vector<long long> ans(1, 0);
  long long X = 0;
  while (X != n) {
    X = memo[X];
    if (X == n) break;
    ans.push_back(X);
    X = MEMO[X];
  }
  reverse((ans).begin(), (ans).end());
  for (long long i = (0); i < (ans.size()); i++) cout << ans[i] << endl;
  return 0;
}
