#include <bits/stdc++.h>
using namespace std;
void solve(string a, string b, int m, int n) {
  int lcs[m + 1][n + 1];
  int result = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        lcs[i][j] = 0;
      else if (a[i - 1] == b[j - 1]) {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
        result = max(result, lcs[i][j]);
      } else
        lcs[i][j] = 0;
    }
  }
  int answer = m + n - 2 * result;
  cout << answer << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, temp;
    cin >> s;
    temp = s;
    sort(s.begin(), s.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (temp[i] != s[i]) count++;
    }
    cout << count << "\n";
  }
  return 0;
}
