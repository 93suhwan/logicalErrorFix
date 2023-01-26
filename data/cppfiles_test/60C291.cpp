#include <bits/stdc++.h>
using namespace std;
const int N = 200010, mod = 1000000007;
int n, m;
int a[N];
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    map<int, int> mp;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mp[a[i]]++;
      sum += a[i];
    }
    if (sum * 2 % n != 0) {
      cout << 0 << endl;
      continue;
    }
    sum = sum * 2 / n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (sum != a[i] * 2)
        ans += mp[sum - a[i]];
      else
        ans += mp[sum - a[i]] - 1;
    }
    cout << ans / 2 << endl;
  }
}
