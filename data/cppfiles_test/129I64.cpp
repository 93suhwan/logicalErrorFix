#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int N = 1e5 + 5;
const long long int mod = 1e9 + 7;
const long long int inf = 1e17;
const long double PI = (acos(-1));
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      ++mp[arr[i]];
    }
    bool flag = true;
    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) {
      if (mp.find(i + 1) != mp.end()) {
        --mp[i + 1];
        res[i] = i + 1;
      }
    }
    auto it = mp.begin();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (it->second <= 0) {
        ++it;
      }
      if (res[i] == 0 && it != mp.end()) {
        if (2 * (i + 2) > (it->first) + 1) {
          flag = false;
          break;
        } else {
          ++ans;
          res[i] = i + 1;
          --it->second;
        }
      } else if (it == mp.end()) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      ans = -1;
    }
    cout << ans << endl;
  }
}
