#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> arr;
  for (auto x : s) {
    if (x == 'a')
      arr.push_back(1);
    else
      arr.push_back(-1);
  }
  map<long long, long long> mp;
  mp[0] = -1;
  long long sum = 0;
  long long l = -1, r = -1;
  for (long long i = 0; i < n; i++) {
    sum += arr[i];
    if (mp.find(sum) != mp.end()) {
      l = mp[sum] + 2;
      r = i + 1;
    }
    mp[sum] = i;
  }
  cout << l << " " << r << "\n";
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
