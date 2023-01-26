#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long pro = sum * 2LL;
    if ((pro % n) != 0) {
      cout << "0\n";
    } else {
      long long target = pro / n, ans = 0;
      map<int, int> mp;
      for (int i = 0; i < n; ++i) {
        ans += mp[target - a[i]];
        mp[a[i]]++;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
