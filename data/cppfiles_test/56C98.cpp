#include <bits/stdc++.h>
using namespace std;
long long n, k;
map<long long, int> mp, marked;
int cnt = 0;
long long dp[120005][6];
long long bigmod(long long x, long long p) {
  if (p == 0) return 1LL;
  long long y = bigmod(x, p / 2);
  if (p % 2 == 1) {
    return ((((y % 1000000007) * (y % 1000000007)) % 1000000007) *
            (x % 1000000007)) %
           1000000007;
  }
  return (y % 1000000007) * (y % 1000000007) % 1000000007;
}
long long solve(long long i, int c) {
  if (mp.count(i) && mp[i] != c) {
    return 0;
  }
  int x = marked[i];
  if (dp[x][c] != -1) return dp[x][c];
  long long ans1 = 0, ans2 = 0;
  if (!marked.count(i * 2))
    ans1 = 1;
  else {
    for (int j = 1; j <= 6; j++) {
      if (j == c) continue;
      if (j % 2 == 0 && c == j - 1) continue;
      if (j % 2 && c == j + 1) continue;
      ans1 += solve(i * 2, j);
      ans1 %= 1000000007;
    }
  }
  if (!marked.count(i * 2 + 1))
    ans2 = 1;
  else {
    for (int j = 1; j <= 6; j++) {
      if (j == c) continue;
      if (j % 2 == 0 && c == j - 1) continue;
      if (j % 2 && c == j + 1) continue;
      ans2 += solve(i * 2 + 1, j);
      ans2 %= 1000000007;
    }
  }
  return dp[x][c] = (ans1 * ans2) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> k >> n;
  while (n--) {
    long long x;
    string color;
    cin >> x >> color;
    if (color[0] == 'w') mp[x] = 1;
    if (color[0] == 'y') mp[x] = 2;
    if (color[0] == 'g') mp[x] = 3;
    if (color[0] == 'b') mp[x] = 4;
    if (color[0] == 'r') mp[x] = 5;
    if (color[0] == 'o') mp[x] = 6;
    while (x) {
      marked[x] = 1;
      x /= 2;
    }
  }
  for (auto i : marked) {
    marked[i.first] = ++cnt;
  }
  long long ans = 0;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= 6; i++) {
    ans += solve(1, i);
    ans %= 1000000007;
  }
  long long node = (1LL << k) - 1;
  node -= marked.size();
  ans *= bigmod(4, node);
  cout << ans % 1000000007 << endl;
}
