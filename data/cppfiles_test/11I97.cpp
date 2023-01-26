#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937_64 rnd;
const long long maxn = 2e5 + 50;
const long long mod = 1e9 + 7;
const long long base = 1e13;
const long long magic = 2000;
long long st[4 * maxn];
struct Seqment_tree {
  long long get(long long id, long long left, long long right, long long x,
                long long y) {
    if (left > y || right < x) return -base;
    if (x <= left && right <= y) {
      return st[id];
    }
    long long mid = (left + right) / 2;
    return max(get(id * 2, left, mid, x, y),
               get(id * 2 + 1, mid + 1, right, x, y));
  }
  void update(long long id, long long left, long long right, long long pos,
              long long diff) {
    if (pos < left || pos > right) return;
    if (left == right) {
      st[id] = diff;
      return;
    }
    long long mid = (left + right) / 2;
    update(id * 2, left, mid, pos, diff);
    update(id * 2 + 1, mid + 1, right, pos, diff);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
  }
} man;
long long dp[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    if (i >= x) {
      long long sl = i - x + 1;
      long long h = man.get(1, 1, n, sl, n) + 1;
      ans = max(ans, h);
      man.update(1, 1, n, sl, h);
    }
  }
  cout << ans;
}
