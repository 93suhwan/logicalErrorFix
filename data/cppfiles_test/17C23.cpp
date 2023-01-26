#include <bits/stdc++.h>
using namespace std;
void DBG() { cerr << "]\n"; }
template <typename T, typename... Args>
void DBG(T first, Args... args) {
  cerr << first;
  if (sizeof...(args)) cerr << ", ";
  DBG(args...);
}
const long long N = 1e6 + 10;
class _fenwick_tree {
 private:
  long long size;
  vector<long long> tree;

 public:
  _fenwick_tree(long long _size) {
    size = _size + 1;
    tree.resize(size);
  }
  _fenwick_tree(vector<long long> &a) {
    size = (long long)(a.size() + 1);
    tree.resize(size);
    for (long long index = 1; index < size; index++) {
      tree[index] += a[index - 1];
      long long j = index + index & (-index);
      if (j < size) tree[j] += tree[index];
    }
  }
  long long sum(long long index) {
    long long res = 0;
    for (++index; index > 0; index -= index & (-index)) res += tree[index];
    return res;
  }
  void update(long long pos, long long val) {
    for (++pos; pos < size; pos += pos & (-pos)) tree[pos] += val;
  }
  long long sum(long long l, long long r) { return sum(r) - sum(l - 1); }
} fen(N);
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<pair<long long, long long>> temp(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    temp[i] = make_pair(a[i], i);
  }
  sort(temp.begin(), temp.end());
  long long s = -1;
  long long val = 0;
  for (long long i = 0; i < n;) {
    while (s + 1 < n && temp[s + 1].first == temp[i].first) {
      s++;
    }
    for (long long j = i; j <= s; j++) {
      a[temp[j].second] = val;
    }
    i = s + 1;
    val++;
  }
  long long ans = 0;
  fen = _fenwick_tree(n + 1);
  for (long long i = 0; i < n; i++) {
    long long op1 = fen.sum(a[i] + 1, n);
    long long op2 = fen.sum(0, a[i] - 1);
    if (op1 < op2) {
      ans += op1;
    } else {
      ans += op2;
    }
    fen.update(a[i], +1);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) {
    solve();
  }
}
