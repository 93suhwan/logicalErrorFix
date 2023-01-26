#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
long long a[N];
map<long long, int> mp;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    mp.clear();
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans = ans + mp[a[i] * n];
      mp[2 * sum - a[i] * n] += 1;
    }
    cout << ans << endl;
  }
  return 0;
}
