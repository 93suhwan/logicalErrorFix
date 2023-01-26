#include <bits/stdc++.h>
using namespace std;
struct {
  bool operator()(const pair<long long, long long>& a,
                  const pair<long long, long long>& b) const {
    return a.second < b.second;
  };
} comp;
template <class E>
class segment_tree {
 public:
  segment_tree(int n) {
    n--, vlen = 2;
    while (n > 0) {
      n >>= 1;
      vlen <<= 1;
    }
    v = vector<E>(vlen);
  }
  void update(int l, int r, int node = -1) {
    if (node == -1) node = vlen - 2;
    if (is_leave(node)) return;
    int m = left(node);
    while (!is_leave(m)) m = right(m);
    if (l <= m) update(l, r, left(node));
    if (r > m) update(l, r, right(node));
    v[node] = v[left(node)] + v[right(node)];
  }
  E query(int l, int r, int node = -1) {
    if (node == -1) node = vlen - 2;
    if (is_leave(node)) return v[node];
    int ml = left(node), m = left(node), mr = right(node);
    while (!is_leave(m)) {
      ml = left(ml), m = right(m), mr = right(mr);
    };
    if (l <= ml && r >= mr) return v[node];
    if (l <= m && r > m)
      return query(l, r, left(node)) + query(l, r, right(node));
    if (l <= m) return query(l, r, left(node));
    return query(l, r, right(node));
  }
  E& operator[](int j) { return v[j]; }

 private:
  int vlen;
  vector<E> v;
  inline int left(int j) { return (j << 1) & (vlen - 1); }
  inline int right(int j) { return left(j) + 1; }
  inline bool is_leave(int j) { return (j & (vlen >> 1)) == 0; }
};
long long solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> ab(n + 1);
  for (long long i = 1; i <= (n); i++) cin >> ab[i].first >> ab[i].second;
  long long t;
  cin >> t;
  long long maxa = 0, maxb = 0;
  for (long long i = 0; i < (t); i++) {
    long long s;
    cin >> s;
    maxa = max(maxa, ab[s].first);
    maxb = max(maxb, ab[s].second);
  }
  sort((ab).begin(), (ab).end(), comp);
  segment_tree<long long> sa(2 * (n + 1));
  for (long long i = 1; i <= (n); i++) {
    sa[ab[i].first] = sa.query(ab[i].first, ab[i].second) + 1;
    sa.update(ab[i].first, ab[i].first);
    if (ab[i].second == maxb) break;
  }
  return sa.query(1, maxa);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ifstream ifs;
  if (""[0]) cin.rdbuf((ifs = ifstream("")).rdbuf());
  ;
  ofstream ofs;
  if (""[0]) cout.rdbuf((ofs = ofstream("")).rdbuf());
  ;
  ofstream lfs;
  if (""[0]) clog.rdbuf((lfs = ofstream("")).rdbuf());
  ;
  int t = 1;
  for (int i = 1; i <= t; i++) {
    auto s = solve();
    cout << s << endl;
  }
}
