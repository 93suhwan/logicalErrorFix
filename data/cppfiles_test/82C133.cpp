#include <bits/stdc++.h>
using namespace std;
vector<int> pre;
int sum(int l, int r) {
  if (l > r) return 0;
  return (l % 2 == 1) ? (pre[r] - pre[l - 1]) : (pre[l - 1] - pre[r]);
}
int rsum(int l, int r, int x) {
  int left = sum(l, x - 1), right = sum(x + 1, r);
  if ((x - l + 1) % 2 == 0) right = 0 - right;
  return left + right;
}
int find(int l, int r) {
  int lb = l, rb = r;
  while (lb < rb) {
    int mid = (lb + rb) >> 1;
    int l1 = rsum(l, r, lb), r1 = rsum(l, r, rb), m1 = rsum(l, r, mid);
    if (l1 == 0) break;
    if (r1 == 0) {
      lb = rb;
      break;
    }
    if (m1 == 0) {
      lb = mid;
      break;
    }
    if ((l1 > 0 && m1 > 0) || (l1 < 0 && m1 < 0))
      lb = mid + 1;
    else
      rb = mid - 1;
  }
  assert(rsum(l, r, lb) == 0);
  return lb;
}
void init() {}
void solve() {
  int n, q;
  cin >> n >> q;
  pre.resize(n + 1);
  string s;
  cin >> s;
  pre[0] = 0;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    int a = (s[i] == '+' ? 1 : -1);
    if (i % 2) a = -a;
    pre[i + 1] = pre[i] + a;
  }
  for (__typeof(q) i = (0) - ((0) > (q)); i != (q) - ((0) > (q));
       i += 1 - 2 * ((0) > (q))) {
    int l, r;
    cin >> l >> r;
    if (sum(l, r) == 0) {
      cout << 0 << endl;
    } else if ((r - l + 1) % 2 == 0) {
      cout << 2 << endl;
      cout << l << " " << find(l + 1, r) << endl;
    } else {
      cout << 1 << endl;
      cout << find(l, r) << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  init();
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
