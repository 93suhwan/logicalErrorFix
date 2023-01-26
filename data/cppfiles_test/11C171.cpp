#include <bits/stdc++.h>
using namespace std;
long long myfun(char ch, long long n, vector<string> v) {
  vector<long long> v1, v2;
  for (long long i = 0; i < n; i++) {
    long long cnt = 0, cn = 0;
    for (long long j = 0; j < v[i].size(); j++) {
      if (v[i][j] == ch)
        cnt++;
      else
        cn++;
    }
    long long dif = cnt - cn;
    if (dif >= 0)
      v1.push_back(dif);
    else
      v2.push_back(dif);
  }
  sort(v1.rbegin(), v1.rend());
  long long ans = 0;
  if (v1.size() == 0 or v1[0] == 0) return ans;
  for (long long i = 0; i < v1.size(); i++) ans += v1[i];
  sort(v2.rbegin(), v2.rend());
  long long val = v1.size();
  for (long long i = 0; i < v2.size(); i++) {
    if ((ans + v2[i]) > 0)
      val++, ans += v2[i];
    else
      break;
  }
  return val;
}
void solve() {
  long long n;
  cin >> n;
  vector<string> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long a = myfun('a', n, v);
  long long b = myfun('b', n, v);
  long long c = myfun('c', n, v);
  long long d = myfun('d', n, v);
  long long e = myfun('e', n, v);
  long long ans = max(a, max(b, c));
  ans = max(ans, max(d, e));
  cout << ans << endl;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  long long q = 1;
  while (t--) {
    solve();
  }
}
