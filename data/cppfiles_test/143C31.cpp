#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int i, j, k, l, m, n, a, b, c, d, u, v, w, t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int arr[n];
    map<long long int, long long int> mp;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
      mp[arr[i]]++;
    }
    sort(arr, arr + n);
    long long int pref[n];
    pref[0] = arr[0];
    for (long long int i = 1; i < n; i++) pref[i] = pref[i - 1] + arr[i];
    long long int sum = 0;
    vector<long long int> ans;
    ans.push_back(mp[0]);
    vector<long long int> v1;
    while (mp[0] > 1) v1.push_back(0), mp[0]--;
    for (long long int i = 1; i <= n; i++) {
      long long int idx = lower_bound(arr, arr + n, i) - arr;
      if (idx < i) break;
      long long int req = mp[i] + sum;
      if (mp[i - 1] == 0) {
        req += (i - 1 - v1.back());
        sum += (i - 1 - v1.back());
        v1.pop_back();
      }
      ans.push_back(req);
      while (mp[i] > 1) v1.push_back(i), mp[i]--;
    }
    while (ans.size() < n + 1) ans.push_back(-1);
    for (auto it : ans) cout << it << " ";
    cout << endl;
  }
}
