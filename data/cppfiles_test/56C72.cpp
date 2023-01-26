#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void mark(long long node, map<long long, long long> &mySet, int color = -1) {
  if (!mySet.count(node) || mySet[node] == -1) mySet[node] = color;
  if (node != 1) mark(node / 2, mySet, -1);
}
int counterPart(int i) {
  return i == 0 ? 1 : i == 1 ? 0 : i == 2 ? 3 : i == 3 ? 2 : i == 4 ? 5 : 4;
}
bool valid(int i, int j) {
  if (i < 2)
    return j > 1;
  else if (i < 4)
    return j > 3 || j < 2;
  return j < 4;
}
void dfs(long long node, map<long long, long long> &mySet,
         map<long long, map<long long, long long> > &dp) {
  dp[node][0] = dp[node][1] = dp[node][2] = dp[node][3] = dp[node][4] =
      dp[node][5] = 0;
  long long LeftNode = node << 1, RightNode = node << 1 | 1;
  bool L = mySet.count(LeftNode), R = mySet.count(RightNode),
       fixed = mySet[node] != -1;
  if (L) dfs(LeftNode, mySet, dp);
  if (R) dfs(RightNode, mySet, dp);
  for (int i = 0; i < 6; i++) {
    if (fixed && mySet[node] != i) continue;
    long long Lchoices = 0, Rchoices = 0;
    if (L) {
      for (int j = 0; j < 6; j++) {
        if (!valid(i, j)) continue;
        Lchoices = (Lchoices + dp[LeftNode][j]) % mod;
      }
    } else
      Lchoices = 1;
    if (R) {
      for (int j = 0; j < 6; j++) {
        if (!valid(i, j)) continue;
        Rchoices = (Rchoices + dp[RightNode][j]) % mod;
      }
    } else
      Rchoices = 1;
    dp[node][i] = (Lchoices * Rchoices) % mod;
  }
}
int main() {
  int t;
  t = 1;
  while (t--) {
    int k, n;
    cin >> k >> n;
    bool alarm = false;
    map<long long, map<long long, long long> > dp;
    map<long long, long long> mySet;
    for (int i = 0; i < n; i++) {
      long long x, which;
      string color;
      cin >> x >> color;
      which = color[0] == 'w'   ? 0
              : color[0] == 'y' ? 1
              : color[0] == 'g' ? 2
              : color[0] == 'b' ? 3
              : color[0] == 'r' ? 4
                                : 5;
      long long Lc = x << 1, Lr = x << 1 | 1LL;
      mark(x, mySet, which);
    }
    if (alarm) {
      cout << 0 << endl;
      continue;
    }
    long long nodesOver = mySet.size();
    long long nodesLeft = (1LL << k) - 1LL - nodesOver;
    dfs(1, mySet, dp);
    long long ans = 0;
    for (int i = 0; i < 6; i++) ans = (ans + dp[1][i]) % mod;
    ans = (ans * power(4, nodesLeft, mod)) % mod;
    cout << ans << endl;
  }
  return 0;
}
