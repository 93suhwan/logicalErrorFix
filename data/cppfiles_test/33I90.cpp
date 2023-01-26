#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  map<long long, set<long long>> mp;
  set<long long> ans;
  ans.insert(0);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]].insert(arr[i]);
    ans.insert(arr[i]);
    for (long long j = arr[i] - 1; j >= 0; j--) {
      if (mp.count(j)) {
        for (auto it : mp[j]) {
          mp[arr[i]].insert(it ^ arr[i]);
          ans.insert(it ^ arr[i]);
        }
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto it : ans) {
    cout << it << " ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  solve();
  return 0;
}
