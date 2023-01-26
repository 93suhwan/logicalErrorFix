#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int tc, cs = 1;
int n, k, cur, arr[N];
int dp[N][N];
int vis[N][N];
int fun(int pos, int rem) {
  if (pos > n) return 0;
  int &ret = dp[pos][rem];
  if (vis[pos][rem] == cs) return ret;
  vis[pos][rem] = cs;
  ret = 0;
  int used = cur - rem;
  ret = fun(pos + 1, rem) + ((pos - used) == arr[pos]);
  if (rem > 0) ret = max(ret, fun(pos + 1, rem - 1));
  return ret;
}
void test_cases() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  int lo = 0, hi = n, ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    cur = mid;
    if (fun(1, mid) >= k) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
    cs++;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    test_cases();
  }
}
