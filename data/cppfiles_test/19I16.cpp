#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long OO = 1e9 + 1;
const int N = 1e4 + 5, M = 100;
int n, m, k, T;
int a, b, c, d;
vector<int> arr;
map<int, pair<int, int>> dp[2];
int Solve() {
  for (int i = 0; i < 2; ++i) dp[i].clear();
  dp[0][arr[0]] = make_pair(0, arr[0]);
  dp[0][-arr[0]] = make_pair(-arr[0], 0);
  for (int i = 1; i < n; ++i) {
    int cur = i & 1;
    int prv = cur ^ 1;
    int val = arr[i];
    dp[cur].clear();
    for (auto it : dp[prv]) {
      int lt = it.first - arr[i], rt = it.first + arr[i];
      if (!dp[cur].count(lt)) {
        dp[cur][lt] = make_pair(min(lt, it.second.first), it.second.second);
      } else {
        int st = min(lt, it.second.first), en = it.second.second;
        if (en - st < dp[cur][lt].second - dp[cur][lt].first)
          dp[cur][lt] = make_pair(st, en);
      }
      if (!dp[cur].count(rt)) {
        dp[cur][rt] = make_pair(it.second.first, max(rt, it.second.second));
      } else {
        int st = it.second.first, en = max(rt, it.second.second);
        if (en - st < dp[cur][rt].second - dp[cur][rt].first)
          dp[cur][rt] = make_pair(st, en);
      }
    }
  }
  int ans = INT_MAX;
  for (auto it : dp[(n - 1) & 1])
    ans = min(ans, it.second.second - it.second.first);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> n;
    arr.resize(n);
    for (auto &it : arr) cin >> it;
    cout << Solve() << "\n";
  }
  return 0;
}
