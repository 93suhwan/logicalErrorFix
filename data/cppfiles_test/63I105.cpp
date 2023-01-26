#include <bits/stdc++.h>
using namespace std;
string s;
int lg[20];
int sum[20], minsum[20][400001];
vector<int> freq[20][800001];
int dp[1 << 20];
int binspref(int ind, int val) {
  int st = 0, dr = lg[ind] - 1, mij;
  while (st <= dr) {
    mij = (st + dr) >> 1;
    if (minsum[ind][mij] <= val)
      dr = mij - 1;
    else
      st = mij + 1;
  }
  return st;
}
int binsfreq(int ind, int nr, int val) {
  int st = 0, dr = freq[ind][nr].size() - 1, mij;
  while (st <= dr) {
    mij = (st + dr) >> 1;
    if (freq[ind][nr][mij] <= val)
      st = mij + 1;
    else
      dr = mij - 1;
  }
  return dr + 1;
}
int main() {
  int n, i, j, x, ans, p;
  const int c = 400000;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    lg[i] = s.size();
    x = 0;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == '(')
        x++;
      else
        x--;
      freq[i][x + c].push_back(j);
      if (j > 0)
        minsum[i][j] = min(minsum[i][j - 1], x);
      else
        minsum[i][j] = x;
    }
    sum[i] = x;
  }
  ans = 0;
  for (i = 1; i < (1 << n); i++) {
    x = 0;
    for (j = 0; j < n; j++)
      if (i & (1 << j)) x = x + sum[j];
    for (j = 0; j < n; j++)
      if (i & (1 << j)) {
        if (minsum[j][lg[j] - 1] + x - sum[j] >= 0)
          dp[i] = max(
              dp[i], dp[i ^ (1 << j)] + int(freq[j][-(x - sum[j]) + c].size()));
        else {
          p = binspref(j, -x + sum[j] - 1);
          p--;
          ans = max(ans, dp[i ^ (1 << j)] + binsfreq(j, -(x - sum[j]) + c, p));
        }
      }
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}
