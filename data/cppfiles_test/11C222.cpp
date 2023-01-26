#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> freq(n, vector<long long>(5, 0));
  vector<string> s(n);
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    for (long long j = 0; j < (long long)((s[i]).size()); j++) {
      freq[i][s[i][j] - 'a']++;
    }
  }
  long long ans = INT_MIN;
  for (long long i = 0; i < 5; ++i) {
    vector<long long> temp;
    for (long long j = 0; j < n; ++j) {
      temp.push_back(freq[j][i] - ((long long)((s[j]).size()) - freq[j][i]));
    }
    sort((temp).begin(), (temp).end(), greater<long long>());
    long long curr = 0, ct = 0;
    for (long long k = 0; k < (long long)((temp).size()); ++k) {
      curr += (temp[k]);
      if (curr > 0) {
        ct++;
      }
    }
    ans = max(ans, ct);
  }
  cout << ans << "\n";
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
