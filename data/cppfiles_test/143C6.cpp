#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
string a, s;
int dp[20][20][2];
int solve(int i, int j, int ok) {
  if (i < 0) return (j < 0 ? ok : 1);
  if (j < 0) return 0;
  int& ret = dp[i][j][ok];
  if (ret != -1) return ret;
  ret = 0;
  for (int k = 0; k < 10; k++) {
    int num = k + a[i] - '0';
    if (s[j] - '0' != num % 10) continue;
    if (num > 9 && (j == 0 || s[j - 1] - '0' != num / 10)) continue;
    ret = solve(i - 1, j - (num > 9 ? 2 : 1), (int)(ok || k));
    if (ret) return ret;
  }
  return ret;
}
string build(int i, int j, int ok) {
  if (i < 0) return s.substr(0, j + 1);
  for (int k = 0; k < 10; k++) {
    int num = k + a[i] - '0';
    if (s[j] - '0' != num % 10) continue;
    if (num > 9 && (j == 0 || s[j - 1] - '0' != num / 10)) continue;
    int ret = solve(i - 1, j - (num > 9 ? 2 : 1), (int)(ok || k));
    if (ret)
      return build(i - 1, j - (num > 9 ? 2 : 1), (int)(ok || k)) +
             string(1, k + '0');
  }
  assert(false);
  return "";
}
int main() {
  file();
  fast();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v1(n), fre(n + 1);
    for (auto& it : v1) {
      cin >> it;
      fre[it]++;
    }
    sort(v1.begin(), v1.end());
    int idx = 0;
    vector<long long> dp(n, -1);
    vector<int> take(n + 1);
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
      while (idx < (int)(v1.size()) && v1[idx] <= i) {
        if (take[v1[idx]]) q.push(v1[idx]);
        take[v1[idx]] = 1;
        idx++;
      }
      if (take[i]) {
        dp[i] = (!i ? 0 : dp[i - 1]);
        continue;
      }
      if ((int)(q.size())) {
        dp[i] = dp[i - 1] + i - q.top();
        q.pop();
        continue;
      }
      break;
    }
    cout << fre[0] << ' ';
    for (int i = 1; i <= n; i++) {
      if (dp[i - 1] != -1)
        cout << dp[i - 1] + fre[i] << ' ';
      else
        cout << "-1 ";
    }
    cout << '\n';
  }
  return 0;
}
