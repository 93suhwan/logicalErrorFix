#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> freq;
  long long ans[n + 1];
  multiset<pair<long long, long long>> mx;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    freq[x]++;
  }
  for (long long i = 0; i <= n; i++)
    if (freq[i] > 1) mx.insert({i, freq[i]});
  ans[0] = freq[0];
  long long i = 1;
  for (i = 1; i <= n; i++) {
    if (freq[i - 1] != 0)
      ans[i] = ans[i - 1] - freq[i - 1] + freq[i];
    else {
      if (mx.size() == 0) {
        ans[i] = -1;
        break;
      }
      multiset<pair<long long, long long>>::iterator it =
          mx.upper_bound({i - 2, 1e9});
      it--;
      long long x = (*it).first;
      long long y = (*it).second;
      if (it == mx.begin() && x >= i) {
        ans[i] = -1;
        break;
      }
      cout << x << " " << i << endl;
      ans[i] = ans[i - 1] + freq[i] + (i - 1 - x);
      if (y - 1 <= 1)
        mx.erase({x, y});
      else {
        mx.erase({x, y});
        mx.insert({x, y - 1});
      }
    }
  }
  for (long long j = i; j <= n; j++) ans[j] = -1;
  for (long long x : ans) cout << x << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
