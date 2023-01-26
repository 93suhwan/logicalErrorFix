#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
string s[N];
int f[N * 2];
int ans2[N];
bool take(string r) {
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 2; j++)
      if (s[i][j] != '?' && s[i][j] != r[j]) return 0;
  return 1;
}
int Mod(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % 998244353;
    a = 1ll * a * a % 998244353;
    b >>= 1;
  }
  return ans;
}
int gt[N], inv[N];
int Cal(int k, int n) {
  if (!k) return 1;
  if (k < 0 || k > n) return 0;
  gt[0] = 1;
  for (int i = 1; i <= n; i++) gt[i] = 1ll * gt[i - 1] * i % 998244353;
  inv[n] = Mod(gt[n], 998244353 - 2);
  for (int i = n; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % 998244353;
  return 1ll * gt[n] * inv[k] % 998244353 * inv[n - k] % 998244353;
}
int main() {
  cin >> n;
  f[N] = 1;
  int dif = 0, xum = 0, left = 0;
  for (int i = 1; i <= n; i++) {
    string r;
    cin >> r;
    if (r[0] == 'B') dif++;
    if (r[0] == '?') xum++;
    if (r[1] == 'W') dif--;
    if (r[1] == '?') xum++, left--;
    s[i] = r;
  }
  int ans = Cal(-dif - left, xum), all = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == "BB" || s[i] == "WW") {
      all = 0;
      break;
    }
    if (s[i] == "??") all = all * 2 % 998244353;
  }
  if (take("BW")) ans++;
  if (take("WB")) ans++;
  cout << (ans - all) % 998244353;
  return 0;
}
