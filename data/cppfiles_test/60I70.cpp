#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
int a[N];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0, flag = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    map<long long, int> mp;
    mp.clear();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += mp[a[i] * n];
      mp[2 * sum - a[i] * n]++;
    }
    cout << ans << endl;
  }
  return 0;
}
