#include <bits/stdc++.h>
using namespace std;
const long long Max = 2e5 + 1;
void nos() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
namespace SegmentTree {
struct Node {
  long long pref = 0;
  long long suf = 0;
  long long val = 0;
  bool is_whole = false;
} tree[4 * Max];
long long rev[Max];
Node merge(Node n1, Node n2) {
  Node ans;
  ans.pref = n1.pref;
  ans.suf = n2.suf;
  ans.val = n1.val + n2.val;
  if (n1.is_whole or n2.is_whole) {
    if (n1.is_whole) ans.pref += n2.pref;
    if (n2.is_whole) ans.suf += n1.suf;
    ans.is_whole = (n1.is_whole and n2.is_whole);
  } else {
    long long inter = n1.suf + n2.pref;
    ans.val += ((inter * (inter + 1)) / 2);
  }
  return ans;
}
long long n;
void init(long long where, long long left, long long right, long long a[]) {
  if (left == right) {
    tree[where].pref = a[left];
    tree[where].suf = a[left];
    if (a[left]) tree[where].is_whole = true;
    rev[left] = where;
    return;
  }
  long long mid = (left + right) / 2;
  init(2 * where, left, mid, a);
  init(2 * where + 1, mid + 1, right, a);
  tree[where] = merge(tree[2 * where], tree[2 * where + 1]);
}
void propagate(long long where) {
  if (where) {
    tree[where] = merge(tree[2 * where], tree[2 * where + 1]);
    propagate(where / 2);
  }
}
void Update(long long pos, long long val) {
  long long pos_in_tree = rev[pos];
  tree[pos_in_tree].pref = val;
  tree[pos_in_tree].suf = val;
  if (val)
    tree[pos_in_tree].is_whole = true;
  else
    tree[pos_in_tree].is_whole = false;
  propagate(pos_in_tree / 2);
}
long long left_limit, right_limit;
vector<Node> elem;
void QueryRange(long long where, long long left, long long right) {
  if (left_limit <= left and right <= right_limit) {
    elem.push_back(tree[where]);
    return;
  }
  long long mid = (left + right) / 2;
  if (left_limit <= mid) QueryRange(2 * where, left, mid);
  if (mid + 1 <= right_limit) QueryRange(2 * where + 1, mid + 1, right);
}
long long Query(long long left, long long right) {
  if (left > right) return 0;
  left_limit = left;
  right_limit = right;
  elem.clear();
  QueryRange(1, 1, n);
  if (elem.empty()) return 0;
  Node ans = elem[0];
  for (long long i = 1; i < elem.size(); i++) ans = merge(ans, elem[i]);
  long long answer = ans.val;
  answer += ((ans.pref * (ans.pref + 1)) / 2);
  if (!ans.is_whole) answer += ((ans.suf * (ans.suf + 1)) / 2);
  return answer;
}
}  // namespace SegmentTree
long long n, q;
long long a[Max];
long long delta[Max];
void read() {
  cin >> n >> q;
  long long i;
  for (i = 1; i <= n; i++) cin >> a[i];
}
void solve() {
  if (n == 1) {
    long long type, x, y;
    while (q--) {
      cin >> type >> x >> y;
      if (type == 2) cout << "1\n";
    }
    return;
  }
  long long i;
  for (i = 1; i < n; ++i) delta[i] = (a[i + 1] >= a[i]);
  SegmentTree::n = n - 1;
  SegmentTree::init(1, 1, n - 1, delta);
  while (q--) {
    long long type;
    cin >> type;
    if (type == 2) {
      long long left, right;
      cin >> left >> right;
      long long single = right - left + 1;
      right--;
      cout << SegmentTree::Query(left, right) + single << '\n';
    } else {
      long long pos, val;
      cin >> pos >> val;
      a[pos] = val;
      if (pos != 1) {
        long long lleft = (a[pos] >= a[pos - 1]);
        if (lleft != delta[pos - 1]) {
          delta[pos - 1] = lleft;
          SegmentTree::Update(pos - 1, lleft);
        }
      }
      if (pos != n) {
        long long rright = (a[pos + 1] >= a[pos]);
        if (rright != delta[pos]) {
          delta[pos] = rright;
          SegmentTree::Update(pos, rright);
        }
      }
    }
  }
}
void restart() {}
int32_t main() {
  nos();
  read();
  solve();
  restart();
  return 0;
}
