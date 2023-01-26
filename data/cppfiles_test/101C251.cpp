#include <bits/stdc++.h>
using namespace std;
long long n, k, a[1000005 + 5], col[1000005];
void solve(long long kk) {
  cin >> n;
  long long neg = 0, mm = 0, nn = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  string s1;
  cin >> s1;
  s1 = 'X' + s1;
  vector<long long> ans, rr, bb;
  for (long long i = 1; i <= n; i++) {
    if (s1[i] == 'R')
      rr.push_back(a[i]);
    else
      bb.push_back(a[i]);
  }
  sort(rr.begin(), rr.end());
  sort(bb.begin(), bb.end());
  for (long long i = n; i >= 1; i--) {
    if (!rr.empty()) {
      if (rr.back() <= i) {
        ans.push_back(i);
        rr.pop_back();
        continue;
      }
    }
    if (!bb.empty()) {
      if (bb.back() >= i) {
        ans.push_back(i);
        bb.pop_back();
        continue;
      }
    }
  }
  sort(ans.begin(), ans.end());
  if (ans.size() < n) {
    cout << "NO\n";
    return;
  }
  for (long long i = 1; i <= n; i++) {
    if (ans[i - 1] != i) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
