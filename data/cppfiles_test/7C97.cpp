#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
long long int modpow(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    res %= mod;
    a = a * a;
    a %= mod;
  }
  return res;
}
long long int p(long long int a, long long int b) {
  long long int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
struct SegTree {
  vector<long long int> tree;
  long long int n = 0;
  long long int def = 0;
  long long int f(long long int a, long long int b) { return gcd(a, b); }
  void init(vector<long long int>& a) {
    n = a.size();
    tree.clear();
    tree.resize(2 * n - 1);
    for (long long int i = (long long int)0; i < (long long int)n; ++i) {
      tree[n - 1 + i] = a[i];
    }
    for (long long int i = (long long int)n - 2; i >= (long long int)0; --i) {
      tree[i] = f(tree[2 * i + 1], tree[2 * i + 2]);
    }
  }
  long long int query(long long int a, long long int b, long long int l,
                      long long int r, long long int node) {
    if (a >= l && b <= r)
      return tree[node];
    else if (a > r || b < l || a > b) {
      return def;
    } else {
      return f(query(a, (a + b) / 2, l, r, 2 * node + 1),
               query((a + b) / 2 + 1, b, l, r, 2 * node + 2));
    }
  }
};
void testcases(long long int test) {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = (long long int)0; i < (long long int)n; ++i)
    cin >> a[i];
  vector<long long int> b(n - 1);
  for (long long int i = (long long int)1; i < (long long int)n; ++i)
    b[i - 1] = abs(a[i] - a[i - 1]);
  long long int N = 1;
  while (N < b.size()) {
    N <<= 1;
  }
  for (long long int i = (long long int)b.size(); i < (long long int)N; ++i)
    b.push_back(0);
  SegTree seg;
  seg.init(b);
  long long int l = 0, r = 0;
  long long int cur = b[0];
  long long int ans = 1;
  while (l < n - 1) {
    while (r < n - 1 && cur > 1) {
      r++;
      if (r < n) cur = seg.query(0, N - 1, l, r, 0);
    }
    ans = ((ans > r - l + 1) ? ans : r - l + 1);
    l++;
    if (r < l) r++;
    cur = seg.query(0, N - 1, l, r, 0);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int i = (long long int)0; i < (long long int)t; ++i)
    testcases(i);
}
