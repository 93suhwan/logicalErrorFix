#include <bits/stdc++.h>
using namespace std;
int prima[100010];
int sudah[100010];
int dp[20010][110];
vector<pair<int, int> > arr;
vector<int> ans, temp;
void sieve() {
  int now = 2;
  while (now <= 100000) {
    if (!sudah[now]) {
      prima[now] = 1;
      int temp = now;
      while (temp <= 100000) {
        sudah[temp] = 1;
        temp += now;
      }
    }
    now++;
    if (now % 2 == 0) {
      now++;
    }
  }
}
int solve(int now, int sum, int cnt) {
  if (now < arr.size()) {
    if (dp[sum][now] == 0) {
      temp.push_back(arr[now].second);
      int first = solve(now + 1, sum + arr[now].first, cnt + 1);
      temp.pop_back();
      int second = solve(now + 1, sum, cnt);
      dp[sum][now] = max(first, second);
    }
  } else if (prima[sum] == 0) {
    if (cnt > ans.size()) {
      ans = temp;
    }
    return cnt;
  }
  return dp[sum][now];
}
int main() {
  sieve();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      arr.push_back(make_pair(a, i));
    }
    cout << solve(0, 0, 0) << endl;
    for (int i = 0; i < ans.size(); i++) {
      if (i) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << endl;
    arr.clear();
    ans.clear();
    memset(dp, 0, sizeof dp);
  }
}
