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
set<pair<long long, long long> > st[4 * maxn];
struct Seqment_tree {
  long long get(long long id, long long left, long long right, long long x,
                long long y, long long h) {
    if (x > right || y < left) return -base;
    if (x <= left && y >= right) {
      auto it = st[id].lower_bound(make_pair(h, -1));
      long long ans = 0;
      if (it != st[id].begin()) {
        it--;
        ans = max(ans, (*it).second);
      }
      return ans;
    }
    long long mid = (left + right) / 2;
    return max(get(id * 2, left, mid, x, y, h),
               get(id * 2 + 1, mid + 1, right, x, y, h));
  }
  void update(long long id, long long left, long long right, long long pos,
              long long h, long long diff) {
    if (pos < left || pos > right) return;
    auto it = st[id].lower_bound(make_pair(h, -1));
    bool chk = true;
    if (it != st[id].begin()) {
      it--;
      if ((*it).second >= diff) {
        chk = false;
      } else {
        it++;
      }
    }
    if (chk) {
      vector<pair<long long, long long> > vt;
      while (it != st[id].end()) {
        auto p = (*it);
        if (diff >= p.second) {
          vt.push_back(p);
          it++;
        } else
          break;
      }
      for (auto to : vt) st[id].erase(to);
      st[id].insert(make_pair(h, diff));
    }
    if (left == right) {
      return;
    }
    long long mid = (left + right) / 2;
    update(id * 2, left, mid, pos, h, diff);
    update(id * 2 + 1, mid + 1, right, pos, h, diff);
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
  long long len = 2 * n;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    if (i >= x) {
      long long h = man.get(1, 1, n, 1, i - x + 1, x) + 1;
      ans = max(ans, h);
      man.update(1, 1, n, i - x + 1, x, h);
    }
  }
  cout << ans;
}
