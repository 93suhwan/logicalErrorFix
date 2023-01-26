#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  int n;
  string str;
  cin >> n >> tc;
  cin >> str;
  vector<char> vc(3);
  vector<vector<int>> dp(6, vector<int>(n + 1, 0));
  vc[0] = 'a';
  vc[1] = 'b';
  vc[2] = 'c';
  int j, a = 0;
  do {
    for (int i = 0; i <= n - 1; i++) {
      dp[a][i + 1] = dp[a][i];
      j = i % 3;
      if (str[i] != vc[j]) dp[a][i + 1]++;
    }
    a++;
  } while (next_permutation(vc.begin(), vc.end()));
  while (tc--) {
    int l, r, ans;
    cin >> l >> r;
    ans = r - l + 1;
    l--;
    for (int i = 0; i < 6; i++) {
      ans = min(ans, dp[i][r] - dp[i][l]);
    }
    cout << ans << endl;
  }
}
