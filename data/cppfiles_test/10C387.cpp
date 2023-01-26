#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const long long N = 1e6 + 50;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) {
    int n, k;
    cin >> n >> k;
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> v;
    map<int, int> cnt;
    int ans[n + 10];
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int temp = 1;
    for (auto j : v) {
      if (mp[{j.first, temp}]) continue;
      ans[j.second] = temp;
      mp[{j.first, temp}] = 1;
      cnt[temp]++;
      temp++;
      if (temp > k) temp = 1;
    }
    int mn = mod;
    for (auto j : cnt) mn = min(mn, j.second);
    for (int i = 0; i < n; i++) {
      if (cnt[ans[i]] > mn) {
        cnt[ans[i]]--;
        ans[i] = 0;
      }
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
