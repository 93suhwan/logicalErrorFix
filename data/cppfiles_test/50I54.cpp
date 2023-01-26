#include <bits/stdc++.h>
using namespace std;
const long long P = 998244353;
inline long long mod(long long x) {
  long long y = x % P;
  return y < 0 ? y + P : y;
}
struct Node {
  struct Node *left = nullptr, *right = nullptr;
  long long sum = 0, lazy = 0;
  bool toShift = false;
};
void push(Node *node, long long l, long long m, long long r) {
  if (not node->left) node->left = new Node();
  if (not node->right) node->right = new Node();
  if (not node->toShift) return;
  node->left->sum = mod((m - l) * node->lazy);
  node->left->lazy = node->lazy;
  node->left->toShift = true;
  node->right->sum = mod((r - m) * node->lazy);
  node->right->lazy = node->lazy;
  node->right->toShift = true;
}
void update(Node *node, long long l, long long r, long long l1, long long r1,
            long long v) {
  if (l1 == r1) return;
  if (l == l1 and r == r1) {
    node->sum = mod((r - l) * v);
    node->lazy = v;
    node->toShift = true;
    return;
  }
  long long m = (l + r) >> 1;
  push(node, l, m, r);
  update(node->left, l, m, min(l1, m), min(r1, m), v);
  update(node->right, m, r, max(l1, m), max(r1, m), v);
  node->sum = mod(node->left->sum + node->right->sum);
}
void test() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long &a1 : a) cin >> a1;
  Node *seg = new Node();
  long long l = 1, r = 1e9 + 1;
  long long m = 1, k = 0;
  update(seg, l, r, 1, a[0] + 1, 1);
  for (long long i = 1; i < n; i++) {
    long long s = mod(m * seg->sum + k * (r - l));
    m = -m;
    k = mod(s - k);
    long long v = mod(-k / m);
    update(seg, l, r, a[i] + 1, r, v);
  }
  cout << mod(m * seg->sum + k * (r - l)) << '\n';
}
signed main() {
  iostream::sync_with_stdio(false);
  long long q = 1;
  while (q--) test();
  assert(cin);
}
