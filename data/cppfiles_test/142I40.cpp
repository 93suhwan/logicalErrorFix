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
    long long hi = 0;
    for (int i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        cin >> mapp[i][j];
        hi = max(hi, mapp[i][j]);
      }
    }
    long long l = 1, r = hi;
    while (l + 1 < r) {
      long long mid = (r + l) / 2;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    cout << l << "\n";
  }
}
