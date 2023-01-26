#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
const long long N = 3e5 + 9;
struct BIT {
  long long size = 1;
  vector<long long> tree;
  void init(long long n) {
    size = n + 1;
    tree.assign(size, 0);
  }
  long long query(long long pos) {
    long long ans = 0;
    while (pos > 0) {
      ans += tree[pos];
      pos -= (pos & -pos);
    }
    return ans;
  }
  void update(long long pos, long long val) {
    while (pos < size) {
      tree[pos] += val;
      pos += (pos & -pos);
    }
  }
};
void solve() {
  long long n, m;
  cin >> n >> m;
  map<long long, vector<long long>> mp;
  for (long long i = 1; i <= n * m; i++) {
    long long x;
    cin >> x;
    mp[x].push_back(i);
  }
  long long ans = 0;
  vector<long long> row;
  for (auto c : mp) {
    vector<long long> v = c.second;
    sort(v.rbegin(), v.rend());
    while (!v.empty()) {
      vector<long long> cur;
      while (!v.empty()) {
        cur.push_back(v.back());
        v.pop_back();
        if (cur.size() + row.size() == m) {
          break;
        }
      }
      reverse(cur.begin(), cur.end());
      for (auto x : cur) row.push_back(x);
      if (row.size() == m) {
        BIT bit;
        bit.init(n * m);
        for (long long i = 0; i < m; i++) {
          ans += bit.query(row[i]);
          bit.update(row[i], 1);
        }
        row.clear();
      }
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
