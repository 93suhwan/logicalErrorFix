#include <bits/stdc++.h>
using namespace std;
long long int maxx(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int minn(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int abss(long long int a, long long int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int cnt[200005][3][3];
int force_match(int l, int r, string mat) {
  int arr[3];
  arr[0] = mat[0] - 'a';
  arr[1] = mat[1] - 'a';
  arr[2] = mat[2] - 'a';
  int len = r - l + 1;
  int fcnt = cnt[r][arr[0]][l % 3] - cnt[l - 1][arr[0]][l % 3];
  int scnt = cnt[r][arr[1]][(l + 1) % 3] - cnt[l - 1][arr[1]][(l + 1) % 3];
  int tcnt = cnt[r][arr[2]][(l + 2) % 3] - cnt[l - 1][arr[2]][(l + 2) % 3];
  return (len - fcnt - scnt - tcnt);
}
int main() {
  int cc = 1, tt = 1;
  while (tt--) {
    int n, m, i;
    string s;
    cin >> n >> m;
    cin >> s;
    cnt[0][0][0] = 0;
    cnt[0][0][1] = 0;
    cnt[0][0][2] = 0;
    cnt[0][1][0] = 0;
    cnt[0][1][1] = 0;
    cnt[0][1][2] = 0;
    cnt[0][2][0] = 0;
    cnt[0][2][1] = 0;
    cnt[0][2][2] = 0;
    for (i = 1; i <= n; i++) {
      int c = s[i - 1] - 'a';
      cnt[i][0][0] = cnt[i - 1][0][0];
      cnt[i][0][1] = cnt[i - 1][0][1];
      cnt[i][0][2] = cnt[i - 1][0][2];
      cnt[i][1][0] = cnt[i - 1][1][0];
      cnt[i][1][1] = cnt[i - 1][1][1];
      cnt[i][1][2] = cnt[i - 1][1][2];
      cnt[i][2][0] = cnt[i - 1][2][0];
      cnt[i][2][1] = cnt[i - 1][2][1];
      cnt[i][2][2] = cnt[i - 1][2][2];
      cnt[i][c][i % 3]++;
    }
    int l, r;
    while (m--) {
      cin >> l >> r;
      int ans = n + 1;
      ans = min(force_match(l, r, "abc"), ans);
      ans = min(force_match(l, r, "acb"), ans);
      ans = min(force_match(l, r, "bca"), ans);
      ans = min(force_match(l, r, "bac"), ans);
      ans = min(force_match(l, r, "cab"), ans);
      ans = min(force_match(l, r, "cba"), ans);
      cout << ans << endl;
    }
  }
}
