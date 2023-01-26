#include <bits/stdc++.h>
using namespace std;
vector<string> v;
long long solve(long long n, char c) {
  vector<pair<long double, pair<long long, long long>>> ans;
  for (long long i = 1; i <= n; i++) {
    string curr = v[i - 1];
    long long cnt = count(curr.begin(), curr.end(), c);
    long long len = curr.length();
    long double now = cnt / (1.0 * len);
    ans.push_back({now, {cnt, 1000000000000000 - len}});
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  long long a = 0, b = 0;
  long long final = 0;
  for (long long i = 0; i < n; i++) {
    a += ans[i].second.first;
    b += 1000000000000000 - ans[i].second.second;
    if (a * 2 <= b) {
      a -= ans[i].second.first;
      b -= 1000000000000000 - ans[i].second.second;
    } else {
      final++;
    }
  }
  return final;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    v.resize(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    long long ans = 0;
    for (long long i = 0; i < 5; i++) {
      char c = 'a' + i;
      ans = max(ans, solve(n, c));
    }
    cout << ans << "\n";
  }
}
