#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;
void pre() {
  for (long long i = 0; i < 63; i++) {
    dp.push_back(pow(2, i));
  }
}
void solution() {
  long long n;
  cin >> n;
  long long ans = INT_MAX;
  string s = to_string(n);
  for (auto x : dp) {
    long long k = 0;
    string p = to_string(x);
    for (long long i = 0; i < s.size(); i++) {
      if (k == p.size()) break;
      if (s[i] == p[k]) k++;
    }
    if (ans > (p.size() + s.size() - k * 2))
      ans = (p.size() + s.size() - k * 2);
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long t;
  cin >> t;
  while (t--) solution();
  return 0;
}
