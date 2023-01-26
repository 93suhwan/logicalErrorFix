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
    sort((arr).begin(), (arr).end());
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      int x = (arr[i] + 1) / 2 - 1;
      if (i + 1 != arr[i] && i + 1 > x) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      cout << "-1\n";
      continue;
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
      if (mp[i + 1] > 0) {
        --ans;
      }
    }
    cout << ans << endl;
  }
}
