#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (auto &zz : arr) cin >> zz;
  vector<long long> ans(501, LLONG_MAX / 2);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 501; j++) {
      if (ans[j] < arr[i]) {
        long long x = (j ^ arr[i]);
        ans[x] = min(ans[x], arr[i]);
      }
    }
    ans[arr[i]] = min(ans[arr[i]], arr[i]);
  }
  vector<long long> fans;
  fans.push_back(0);
  for (long long i = 1; i < 501; i++) {
    if (ans[i] != LLONG_MAX / 2) fans.push_back(i);
  }
  cout << fans.size() << "\n";
  for (auto zz : fans) cout << zz << " ";
  cout << "\n";
  return 0;
}
