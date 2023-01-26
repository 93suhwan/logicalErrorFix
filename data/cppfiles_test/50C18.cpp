#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<long long> dp(n + 2);
  vector<long long> sum(n + 2);
  vector<long long> ndp(n + 2);
  sum[0] = dp[0] = 0;
  sum[1] = dp[1] = 1;
  stack<int> st;
  st.push(0);
  a[0] = 0;
  for (int i = 1, idx; i <= n; i++) {
    idx = st.top();
    while (a[idx] >= a[i]) {
      st.pop();
      idx = st.top();
    }
    st.push(i);
    i++;
    idx++;
    ndp[i] = (ndp[idx] + (sum[i - 1] - sum[idx - 1]) * a[i - 1]) % mod;
    dp[i] = (i % 2 == 1 ? -1 : 1) * ndp[i];
    sum[i] = (sum[i - 1] + (i % 2 == 1 ? 1 : -1) * dp[i]) % mod;
    i--;
  }
  cout << (dp[n + 1] + mod) % mod << '\n';
  return 0;
}
