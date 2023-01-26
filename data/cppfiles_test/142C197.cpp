#include <bits/stdc++.h>
using namespace std;
long long n, t, m, k, test;
const long long MAX = 1e6;
vector<vector<long long>> mapp;
bool check(long long x) {
  vector<bool> abl(n);
  bool flag = false;
  for (long long i = 0; i < m; i++) {
    long long c = 0;
    for (long long j = 0; j < n; j++) {
      if (mapp[i][j] >= x) {
        abl[j] = true;
        c++;
      }
    }
    if (c > 1) flag = true;
  }
  if (!flag) return false;
  bool ans = true;
  for (auto check : abl) {
    ans &= check;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> m >> n;
    mapp = vector<vector<long long>>(m, vector<long long>(n));
    for (int i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        cin >> mapp[i][j];
      }
    }
    long long ans = 0;
    long long l = 1, r = 1e9;
    while (l <= r) {
      long long mid = (r + l) / 2;
      if (check(mid)) {
        l = mid + 1;
        ans = max(ans, mid);
      } else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
}
