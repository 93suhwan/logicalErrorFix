#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n, a[N];
map<int, int> mp;
int main() {
  cin >> T;
  while (T--) {
    int sum = 0;
    mp.clear();
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    int mean = sum / n;
    if (sum % n != 0) {
      cout << 0 << endl;
      continue;
    }
    int sum1 = mean * (n - 2), need = sum - sum1, cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (mp.find(need - a[i]) != mp.end()) cnt += mp[need - a[i]];
      mp[a[i]]++;
    }
    cout << cnt << endl;
  }
  return 0;
}
