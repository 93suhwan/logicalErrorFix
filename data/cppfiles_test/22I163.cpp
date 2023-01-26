#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> a;
  for (int i = 0; i < k; ++i) {
    int m;
    cin >> m;
    long long x = 0;
    for (int j = 0; j < m; ++j) {
      int p;
      cin >> p;
      --p;
      x |= 1 << p;
    }
    a.push_back(x);
  }
  function<void(int, long long, long long)> dfs = [&](int p, long long cur,
                                                      long long vis) {
    if (p == k) {
      if (vis != (1 << n) - 1 || __builtin_popcount(cur + 1) != 1) {
        cout << "REJECTED" << endl;
        exit(0);
      }
      return;
    }
    int cnt_one = __builtin_popcount(cur & a[p]);
    int cnt_first_visit = __builtin_popcount(~vis & a[p]);
    vis |= a[p];
    long long nxt = cur & ~a[p], mask = a[p];
    for (int i = 0; i <= cnt_one + cnt_first_visit; ++i) {
      if (i >= cnt_one) dfs(p + 1, nxt, vis);
      int low_bit = mask & -mask;
      mask ^= low_bit;
      nxt ^= low_bit;
    }
  };
  dfs(0, 0, 0);
  cout << "ACCEPTED" << endl;
}
