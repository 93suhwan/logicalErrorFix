#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long space = 2e3 + 5;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long _ = 1, n, m, k, a, b, c;
  cin >> _;
outer:
  while (_--) {
    cin >> n;
    vector<string> words(n);
    vector<vector<long long>> cnt(5, vector<long long>(n, 0));
    for (long long i = 0; i < n; i++) {
      cin >> words[i];
      string z = words[i];
      for (long long j = 0; j < z.size(); j++) {
        cnt[z[j] - 'a'][i]++;
      }
    }
    long long ans = 0;
    for (long long i = 0; i < 5; i++) {
      vector<long long> arr(n);
      for (long long j = 0; j < n; j++) {
        arr[j] = cnt[i][j] - (words[j].size() - cnt[i][j]);
      }
      sort(arr.begin(), arr.end(), greater<long long>());
      long long tmp = 0;
      for (long long j = 0; j < n; j++) {
        tmp += arr[j];
        if (tmp > 0) ans = max(ans, j + 1);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
