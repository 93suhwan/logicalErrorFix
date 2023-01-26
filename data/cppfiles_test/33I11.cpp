#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0, 0, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0, 0, 0};
long long n;
vector<long long> a;
long long can[512][512];
long long dp[550][550];
long long recur(long long node, long long cur) {
  if (cur == 0) return 1;
  if (node == 511) {
    return 0;
  }
  if (dp[node][cur] != -1) return dp[node][cur];
  long long ans = 0;
  for (int i = node + 1; i < 512; i++) {
    if (can[node][i] == 1) {
      ans = ans | recur(i, cur ^ i);
    }
  }
  return dp[node][cur] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  a.push_back(0);
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  n = a.size();
  long long f[512];
  memset(f, 0, sizeof(f));
  memset(can, 0, sizeof(can));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i]; j++) {
      if (f[j] == 1) {
        can[j][a[i]] = 1;
      }
    }
    f[a[i]] = 1;
  }
  memset(dp, -1, sizeof(dp));
  vector<long long> ans;
  for (int i = 0; i < 512; i++) {
    if (recur(0, i)) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
