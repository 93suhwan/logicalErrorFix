#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 1e4 + 5;
int main() {
  cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;
    sort(v.begin(), v.end());
    long long cnt = 2 * k;
    map<long long, long long> mp;
    while (cnt--) {
      mp[v.back()]++;
      v.pop_back();
    }
    int ans = 0;
    for (auto& it : mp)
      if (it.second > k) ans += it.second - k;
    for (auto& x : v) ans += x;
    cout << ans << endl;
  }
}
