#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, q;
  cin >> n >> q;
  string str;
  cin >> str;
  string p = "abc";
  vector<vector<long long>> per;
  long long cur = 0;
  do {
    vector<long long> temp(n);
    for (long long i = 0; i < n; i++) {
      if (i == 0)
        temp[i] = (p[i % 3] != str[i]);
      else
        temp[i] = temp[i - 1] + (p[i % 3] != str[i]);
    }
    per.push_back(temp);
  } while (next_permutation((p).begin(), (p).end()));
  while (q--) {
    long long l, r;
    cin >> l >> r;
    long long ans = INT_MAX;
    for (long long i = 0; i < 6; i++) {
      long long cur;
      if (l == 1) {
        cur = per[i][r - 1];
      } else {
        if (r == n) r = n - 1;
        cur = per[i][r] - per[i][l - 2];
      }
      ans = min(ans, cur);
    }
    cout << ans << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
