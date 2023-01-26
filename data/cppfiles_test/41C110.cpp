#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int sum[10][maxn];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string ans[10];
  ans[1] = "abc";
  ans[2] = "acb";
  ans[3] = "bac";
  ans[4] = "bca";
  ans[5] = "cab";
  ans[6] = "cba";
  for (int j = 1; j <= 6; j++) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      sum[j][i + 1] = sum[j][i];
      if (s[i] != ans[j][i % 3]) sum[j][i + 1]++;
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    int minn = 1e8;
    for (int j = 1; j <= 6; j++) {
      minn = min(minn, sum[j][r] - sum[j][l - 1]);
    }
    cout << minn << endl;
  }
}
