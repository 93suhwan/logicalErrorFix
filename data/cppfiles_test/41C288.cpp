#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long powx(long long a, long long p) {
  long long ans = 1;
  for (int i = 0; i < p; i++) ans *= a;
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string s1, s2, s3, s4, s5, s6;
  for (int i = 0; i < n / 3; i++) {
    s1 += "abc";
    s2 += "acb";
    s3 += "bca";
    s4 += "bac";
    s5 += "cab";
    s6 += "cba";
  }
  if (n % 3 == 2) {
    s1 += "ab";
    s2 += "ac";
    s3 += "bc";
    s4 += "ba";
    s5 += "ca";
    s6 += "cb";
  }
  if (n % 3 == 1) {
    s1 += "a";
    s2 += "a";
    s3 += "b";
    s4 += "b";
    s5 += "c";
    s6 += "c";
  }
  int diff[n + 1][7];
  memset(diff, 0, sizeof(diff));
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] != s1[i - 1]) {
      diff[i][1] = diff[i - 1][1] + 1;
    } else
      diff[i][1] = diff[i - 1][1];
    if (s[i - 1] != s2[i - 1]) {
      diff[i][2] = diff[i - 1][2] + 1;
    } else
      diff[i][2] = diff[i - 1][2];
    if (s[i - 1] != s3[i - 1]) {
      diff[i][3] = diff[i - 1][3] + 1;
    } else
      diff[i][3] = diff[i - 1][3];
    if (s[i - 1] != s4[i - 1]) {
      diff[i][4] = diff[i - 1][4] + 1;
    } else
      diff[i][4] = diff[i - 1][4];
    if (s[i - 1] != s5[i - 1]) {
      diff[i][5] = diff[i - 1][5] + 1;
    } else
      diff[i][5] = diff[i - 1][5];
    if (s[i - 1] != s6[i - 1]) {
      diff[i][6] = diff[i - 1][6] + 1;
    } else
      diff[i][6] = diff[i - 1][6];
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    int ans = 1000000007;
    for (int i = 1; i < 7; i++) {
      ans = min(ans, diff[r][i] - diff[l - 1][i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
