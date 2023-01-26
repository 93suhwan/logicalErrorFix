#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long LINF = 1e18;
int a[N];
int dp[N];
vector<int> vec[N];
int main() {
  freopen("out.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    vec[a[i]].push_back(i);
  }
  for (int i = 1; i <= 9000; i++) dp[i] = INF;
  for (int i = 1; i <= 5000; i++)
    for (int j = 0; j <= 9000; j++) {
      int idx =
          upper_bound(vec[i].begin(), vec[i].end(), dp[j]) - vec[i].begin();
      if (idx < vec[i].size()) dp[i ^ j] = min(dp[i ^ j], vec[i][idx]);
    }
  vector<int> ans;
  for (int i = 0; i <= 9000; i++)
    if (dp[i] != INF) ans.push_back(i);
  printf("%d\n", ans.size());
  for (auto x : ans) printf("%d ", x);
  puts("");
}
