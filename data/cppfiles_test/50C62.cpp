#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int MOD = 998244353;
inline int add(int a, int b) { return (a + b >= MOD) ? a + b - MOD : a + b; }
inline void inc(int &a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return (a - b < 0) ? a - b + MOD : a - b; }
inline void dec(int &a, int b) { a = sub(a, b); }
inline int mul(int a, int b) { return 1ll * a * b % MOD; }
inline void grow(int &a, int b) { a = mul(a, b); }
int n, arr[N], prv[N], nxt[N], dp[N][2], sum[N][2], dif[N][2];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  stack<int> st;
  st.push(0);
  for (int i = 1; i <= n; ++i) {
    while (arr[st.top()] > arr[i]) st.pop();
    prv[i] = st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  st.push(n + 1);
  for (int i = n; i >= 1; --i) {
    while (arr[st.top()] >= arr[i]) st.pop();
    nxt[i] = st.top();
    st.push(i);
  }
  dp[0][0] = sum[0][0] = 1;
  dec(dif[1][1], 1);
  for (int i = 1; i <= n; ++i) {
    int tmp[2] = {
        sub(sum[i - 1][0], prv[i] ? sum[prv[i] - 1][(i - prv[i]) & 1] : 0),
        sub(sum[i - 1][1], prv[i] ? sum[prv[i] - 1][(i - prv[i] + 1) & 1] : 0)};
    inc(dif[i][0], mul(arr[i], tmp[0]));
    inc(dif[i][1], mul(arr[i], tmp[1]));
    dec(dif[nxt[i]][(nxt[i] - i) & 1], mul(arr[i], tmp[0]));
    dec(dif[nxt[i]][(nxt[i] - i + 1) & 1], mul(arr[i], tmp[1]));
    dp[i][0] = add(dp[i - 1][1], dif[i][0]);
    dp[i][1] = add(dp[i - 1][0], dif[i][1]);
    sum[i][0] = add(sum[i - 1][1], dp[i][0]);
    sum[i][1] = add(sum[i - 1][0], dp[i][1]);
  }
  cout << sub(dp[n][0], dp[n][1]) << '\n';
}
