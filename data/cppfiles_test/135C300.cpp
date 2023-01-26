#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int x24e;
  cin >> x24e;
  for (long long int TC = 1; TC <= x24e; TC++) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    map<long long int, long long int> mp;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long int ans = 0;
    vector<long long int> first, second;
    for (long long int i = 0; i < n - k; i++) first.push_back(arr[i]);
    for (long long int i = n - k; i < n; i++) {
      second.push_back(arr[i]);
    }
    while (!second.empty()) {
      if (first.empty()) break;
      long long int x = first.back();
      first.pop_back();
      if (x == second.back()) ans++;
      second.pop_back();
    }
    for (auto i : first) {
      ans += i;
    }
    cout << ans << "\n";
  }
  return 0;
}
