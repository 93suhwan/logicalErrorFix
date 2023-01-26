#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long c[5005][5005];
void get_c() {
  c[0][0] = 1;
  for (int i = 1; i <= 5000; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
}
int a[5005];
int main() {
  get_c();
  a[0] = 0;
  int nnow = 0;
  int n, k;
  long long ans = 1;
  cin >> n >> k;
  string s;
  cin >> s;
  int i = 0;
  while (i < n) {
    if (s[i] == '1') {
      nnow++;
      a[nnow] = i + 1;
    }
    if (nnow >= k) {
      int l = a[nnow - k] + 1;
      int r = i + 1;
      int tt = k - 1;
      if (s[i] == '1') {
        tt++;
      }
      ans = (ans + c[r - l][tt]) % mod;
    }
    i++;
  }
  if (k == 0) ans = 1;
  cout << ans << endl;
  return 0;
}
