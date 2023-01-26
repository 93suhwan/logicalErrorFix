#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
long long n, num[23][26], mod = 998244353, mn[26], inv[20004], aa[8500006],
                          dp[8500006], summ[8500006], ans;
long long pw(long long x, long long y) {
  if (y == 0) return 1;
  long long ans = pw(x, y / 2);
  ans = (ans * ans) % mod;
  if (y % 2) ans = (ans * x) % mod;
  return ans;
}
void go(int x, int mask, long long nm, long long sum, long long ad) {
  long long nnn = __builtin_popcount(mask);
  if (x == n) {
    if (nnn % 2)
      dp[mask] = ad;
    else
      dp[mask] = -1 * ad;
    summ[mask] = sum;
    return;
  }
  go(x + 1, mask, nm, sum, ad);
  long long last[26], add = ad;
  for (int i = 0; i < 26; i++) {
    last[i] = mn[i];
    if (mn[i] > num[x][i]) {
      if (mn[i] != 1e6) add = (add * inv[mn[i] + 1]) % mod;
      add = (add * (num[x][i] + 1)) % mod;
    }
    mn[i] = min(mn[i], num[x][i]);
  }
  go(x + 1, (mask | (1 << x)), nm + 1, sum + x + 1, add);
  for (int i = 0; i < 26; i++) mn[i] = last[i];
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) num[i][s[j] - 'a']++;
  }
  for (int i = 0; i < 26; i++) mn[i] = 1e6;
  for (int i = 0; i <= 2e4; i++) inv[i] = pw(i, mod - 2);
  go(0, 0, 0, 0, 1);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if ((mask & (1 << i))) dp[mask] += dp[(mask ^ (1 << i))];
    }
  }
  for (int mask = 0; mask < (1 << n); mask++)
    ans ^= summ[mask] * dp[mask] * __builtin_popcount(mask);
  cout << ans;
}
