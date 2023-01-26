#include <bits/stdc++.h>
using namespace std;
vector<string> v;
long long solve(long long n, char c) {
  vector<long long> ans;
  for (long long i = 1; i <= n; i++) {
    string curr = v[i - 1];
    long long cnt = count(curr.begin(), curr.end(), c);
    long long len = curr.length();
    long long diff = cnt - (len - cnt);
    ans.push_back(diff);
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  long long final = 0;
  for (long long i = 0; i < n; i++) {
    long long curr = ans[i];
    if ((final + curr) > 0) {
      final += curr;
    } else {
      return i;
    }
  }
  return n;
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
