#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
const double PI = 4 * atan(1);
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n), ans(n + 1, -1);
  multiset<long long int> s;
  map<long long int, long long int> mp;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    s.insert(arr[i]);
    mp[arr[i]]++;
  }
  sort(arr.begin(), arr.end());
  long long int val = 0, flag = 1;
  for (long long int i = 0; i < n; i++) {
    if (mp[i]) {
      ans[i] = val + mp[i];
      s.erase(s.find(i));
    } else {
      auto it = s.lower_bound(i);
      ans[i] = val;
      long long int temp;
      if (it == s.begin()) {
        flag = 0;
        break;
      } else {
        it--;
        temp = *it;
      }
      s.erase(s.find(temp));
      val += abs(i - temp);
    }
  }
  if (flag) {
    ans[arr.size()] = val;
  }
  for (long long int i = 0; i < (long long int)ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
