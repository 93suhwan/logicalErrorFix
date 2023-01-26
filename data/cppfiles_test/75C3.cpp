#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200010;
const long long INF = 2147483647;
long long n, maxx, pos1, pos2, a[maxn], dp[maxn];
bool flag = false;
bool dfs(long long pos, long long lp, long long rp, long long le,
         long long re) {
  if (pos == le || pos == re) return true;
  if (pos == lp) {
    if (a[pos] >= a[rp]) return (((le - pos) & 1) == 0);
    bool pd = false;
    pd |= dfs(pos + 1, lp + 1, rp, le, re);
    pd |= dfs(rp, lp + 1, rp, le, re);
    return (pd == false);
  } else {
    if (a[pos] >= a[lp]) return (((pos - re) & 1) == 0);
    bool pd = false;
    pd |= dfs(pos - 1, lp, rp - 1, le, re);
    pd |= dfs(lp, lp, rp - 1, le, re);
    return (pd == false);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  maxx = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    maxx = max(maxx, a[i]);
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    if (a[i] >= a[i + 1]) {
      pos1 = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] >= a[i - 1]) {
      pos2 = i;
      break;
    }
  }
  flag |= dfs(1, 1, n, pos1, pos2);
  flag |= dfs(n, 1, n, pos1, pos2);
  cout << (flag == true ? "Alice" : "Bob");
  return 0;
}
