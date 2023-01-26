#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n), temp(n);
  for (auto &x : arr) cin >> x;
  temp = arr;
  sort((arr).begin(), (arr).end());
  unordered_map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    mp[arr[i]] = i;
  }
  long long nk = 1;
  long long prev = temp[0];
  for (long long i = 1; i < n; i++) {
    long long ind = mp[prev] + 1;
    if (ind == n || (ind != n && arr[ind] != temp[i])) nk++;
    prev = temp[i];
  }
  if (nk <= k)
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
