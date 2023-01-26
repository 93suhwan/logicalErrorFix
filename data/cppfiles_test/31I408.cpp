#include <bits/stdc++.h>
using namespace std;
void solve(long long nn) {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> vp;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[i] = x;
    vp.push_back({x, i});
  }
  sort(vp.begin(), vp.end());
  long long second = 0;
  long long iid = -1;
  long long kk = INT_MAX;
  for (long long i = 0; i < n; i++) {
    long long val = vp[i].first;
    if (abs(val) < kk) {
      kk = abs(val);
      iid = i;
    }
  }
  long long k = vp[iid].first;
  long long ans[n];
  for (long long i = n - 1; i >= 0; i--) {
    if (i == iid) continue;
    pair<long long, long long> p = vp[i];
    long long id = p.second;
    long long val = p.first;
    long long zz = abs(val);
    if (i == 1) {
      if (second > 0) {
        if (val > 0) {
          ans[id] = kk;
          second += zz * kk;
        } else {
          ans[id] = -kk;
          second += zz * kk;
        }
      } else {
        if (val > 0) {
          ans[id] = -1 * kk;
          second -= zz * kk;
        } else {
          ans[id] = kk;
          second -= zz * kk;
        }
      }
      continue;
    }
    if (second > 0) {
      if (val > 0) {
        ans[id] = -1 * kk;
        second -= zz * kk;
      } else {
        ans[id] = kk;
        second -= zz * kk;
      }
    } else {
      if (val > 0) {
        ans[id] = kk;
        second += zz * kk;
      } else {
        ans[id] = -kk;
        second += zz * kk;
      }
    }
  }
  ans[vp[iid].second] = -1 * second / vp[iid].first;
  long long ss = 0;
  for (long long i = 0; i < n; i++) {
    ss += ans[i] * a[i];
    cout << ans[i] << " ";
  }
  cout << "\n";
  return;
}
int main() {
  std::cout << std::fixed;
  std::cout << std::setprecision(15);
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
