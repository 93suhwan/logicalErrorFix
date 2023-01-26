#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
const long long MX = 2e5 + 105;
int sum[6][MX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    int n, m;
    string str;
    cin >> n >> m;
    cin >> str;
    string p[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 6; j++) {
        sum[j][i + 1] = sum[j][i];
        if (str[i] != p[j][i % 3]) sum[j][i + 1]++;
      }
    }
    while (m--) {
      int l, r;
      cin >> l >> r;
      int ans = 2e9;
      for (int i = 0; i < 6; i++) {
        ans = min(ans, sum[i][r] - sum[i][l - 1]);
      }
      cout << ans << endl;
    }
  }
}
