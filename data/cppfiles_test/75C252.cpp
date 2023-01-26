#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, vector<long long>>> A(n);
  auto find_ans = [&](long long MID) {
    bool ok = 1;
    for (long long i = 0; i < n; i++) {
      if (MID <= A[i].first) {
        ok = 0;
        break;
      }
      MID += (A[i].second.size());
    }
    if (!ok) return 0LL;
    return MID;
  };
  for (long long i = 0; i < n; i++) {
    long long z;
    cin >> z;
    for (long long j = 0; j < z; j++) {
      long long y;
      cin >> y;
      A[i].second.push_back(y - j);
    }
    A[i].first = *max_element((A[i].second).begin(), (A[i].second).end());
  }
  sort((A).begin(), (A).end());
  long long left = 0, right = 1e18, myans = 0;
  while (left <= right) {
    long long m = left + (right - left) / 2;
    if (find_ans(m)) {
      myans = m;
      right = m - 1;
    } else
      left = m + 1;
  }
  cout << myans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
