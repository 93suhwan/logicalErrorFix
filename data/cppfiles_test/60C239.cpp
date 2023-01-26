#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n, a[N];
map<int, int> mp;
int main() {
  cin >> T;
  while (T--) {
    double sum = 0;
    mp.clear();
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    double mean = sum / n;
    double need = sum - (n - 2) * mean;
    if (need != floor(need)) {
      cout << 0 << endl;
      continue;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (mp.find(need - a[i]) != mp.end()) ans += mp[need - a[i]];
      mp[a[i]]++;
    }
    cout << ans << endl;
  }
  return 0;
}
