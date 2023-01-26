#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n, m;
long long g[N], c[N];
long long solve() {
  stack<long long> st;
  long long x;
  cin >> n;
  for (long long i = 0; i <= n; i++) g[i] = 0;
  for (long long i = 1; i <= n; i++) cin >> x, g[x]++;
  for (long long i = 1; i <= g[0] - 1; i++) st.push(0);
  for (long long i = 1; i <= n; i++) {
    if (c[i - 1] == -1) {
      c[i] = -1;
      continue;
    }
    if (g[i] == 0) {
      if (st.empty())
        c[i] = -1;
      else
        c[i] = c[i - 1] + i - st.top(), st.pop();
    } else
      c[i] = c[i - 1];
    for (long long j = 1; j <= g[i] - 1; j++) st.push(i);
  }
  long long ans;
  for (long long i = 0; i <= n; i++) {
    if (i == 0)
      ans = g[0];
    else {
      if (c[i - 1] == -1)
        ans = -1;
      else
        ans = c[i - 1] + g[i];
    }
    cout << ans << " ";
  }
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
