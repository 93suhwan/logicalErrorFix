#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    multiset<long long> s;
    set<long long> req;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      req.insert(i + 1);
      s.insert(i + 1);
    }
    req.insert(-1);
    sort(arr, arr + n);
    long long ans = 0;
    for (auto cur : arr) {
      long long maxi = cur / 2;
      if (cur % 2 == 0) maxi--;
      if (req.find(cur) != req.end()) {
        req.erase(cur);
        continue;
      }
      long long ele = *--req.lower_bound(maxi);
      if (req.find(maxi) != req.end()) {
        req.erase(maxi);
        ans++;
        continue;
      }
      if (ele != -1) {
        req.erase(ele);
        ans++;
      }
    }
    if (req.size() != 1) {
      ans = -1;
    }
    cout << ans << "\n";
  }
}
