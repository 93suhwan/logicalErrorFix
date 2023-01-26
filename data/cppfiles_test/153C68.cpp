#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, cnt[23][20003];
string s[23];
int alls[(1 << 23)];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < s[i].size(); j++) cnt[i][s[i][j] - 'a']++;
  for (int i = 0; i < (1 << n); i++) {
    long long nw = 1;
    for (int j = 0; j < 26; j++) {
      int minn = mod;
      for (int k = 0; k < n; k++)
        if ((1 << k) & i) minn = min(minn, cnt[k][j]);
      nw = 1ll * nw * (minn + 1) % mod;
    }
    alls[i] = nw;
  }
  for (int j = 0; j < n; j++)
    for (int i = (1 << n) - 1; i >= 0; i--)
      if (!(i & (1 << j))) {
        alls[i] -= alls[i + (1 << j)];
        if (alls[i] < 0) alls[i] += mod;
      }
  alls[0] = 0;
  for (int j = 0; j < n; j++)
    for (int i = 0; i < (1 << n); i++)
      if (i & (1 << j)) {
        alls[i] += alls[i - (1 << j)];
        if (alls[i] >= mod) alls[i] -= mod;
      }
  long long ans = 0, res;
  for (int i = 1; i < (1 << n); i++) {
    res = alls[(1 << n) - 1] - alls[(1 << n) - 1 ^ i];
    if (res < 0) res += mod;
    res = res * __builtin_popcount(i);
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) cnt += (j + 1);
    res = res * cnt;
    ans ^= res;
  }
  cout << ans;
}
