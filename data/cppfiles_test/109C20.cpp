#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
string s[N];
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
int Cal(int k, int n) {
  if (!k) return 1;
  if (k < 0 || k > n) return 0;
  int ans = 1, gt = 1;
  for (int i = 1; i <= n; i++) {
    gt = 1ll * gt * i % 998244353;
    if (i == k) ans = 1ll * ans * Mod(gt, 998244353 - 2) % 998244353;
    if (i == n - k) ans = 1ll * ans * Mod(gt, 998244353 - 2) % 998244353;
  }
  return 1ll * ans * gt % 998244353;
}
int main() {
  cin >> n;
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
  cout << (ans + 998244353 + take("BW") + take("WB") - all) % 998244353;
  return 0;
}
