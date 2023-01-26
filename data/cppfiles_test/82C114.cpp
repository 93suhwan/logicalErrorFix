#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> l(q), r(q);
  for (int i = 0; i < q; ++i) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }
  vector<int> pre(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      s[i] = (s[i] == '+' ? '-' : '+');
    }
    int nx = s[i] == '+' ? 1 : -1;
    pre[i + 1] = pre[i] + nx;
  }
  vector<int> plus_before(n, 0), minus_after(n, 0);
  for (int i = 1; i < n; ++i) {
    plus_before[i] = plus_before[i - 1];
    if (s[i - 1] == '+') {
      plus_before[i]++;
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    minus_after[i] = minus_after[i + 1];
    if (s[i + 1] == '-') {
      minus_after[i]++;
    }
  }
  map<int, set<int>> inds;
  for (int i = 0; i < n; ++i) {
    int sm = plus_before[i] + minus_after[i];
    inds[sm].insert(i);
  }
  for (int i = 0; i < q; ++i) {
    if (pre[r[i] + 1] - pre[l[i]] == 0) {
      cout << 0 << '\n';
      continue;
    } else if ((r[i] - l[i]) % 2 == 0) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
      cout << r[i] + 1 << ' ';
      r[i]--;
    }
    int goal = (r[i] - l[i] + 1) / 2;
    int sub = plus_before[l[i]] + minus_after[r[i]];
    set<int>& cands = inds[goal + sub];
    auto it = cands.lower_bound(l[i]);
    if (it == cands.end() || *it > r[i]) {
      assert(false);
    }
    cout << *it + 1 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
