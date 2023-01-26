#include <bits/stdc++.h>
using namespace std;
mt19937 mrand(random_device{}());
const long long mod = 1000000007;
const long long mod2 = 998244353;
int rnd(int x) { return mrand() % x; }
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
vector<int> pos[10];
int cnt;
long long pw[15], s[15];
long long cnt2, n;
int ans;
int query(int fixpre, long long val) {
  long long ans = 0;
  for (int d = 0; d < 7; d++) {
    long long offset = (val - fixpre * pw[d]) % mod2;
    if (offset < 0) offset += mod2;
    int p = lower_bound((pos[d]).begin(), (pos[d]).end(), mod2 - offset) -
            pos[d].begin();
    ans = (ans + s[d] + offset * ((int)(pos[d]).size()) -
           mod2 * (((int)(pos[d]).size()) - p)) %
          mod;
  }
  return ans;
}
void dfs(int val, int d) {
  int x = (cnt - val + mod2) % mod2;
  pos[d].push_back(x);
  cnt++;
  s[d] += x;
  if (d == 6) return;
  for (int i = 0; i < 10; i++) dfs(val * 10 + i, d + 1);
}
void dfs2(long long val) {
  if (val * 1000000 + 999999 <= n && val * 10000000 > n) {
    ans = (ans + query(val, cnt2 + 1)) % mod;
    cnt2 += cnt;
  } else {
    cnt2++;
    ans = (ans + ((cnt2 - val) % mod2 + mod2) % mod2) % mod;
    for (int i = val ? 0 : 1; i < 10; i++) {
      if (val * 10 + i <= n) dfs2(val * 10 + i);
    }
  }
}
int main() {
  dfs(0, 0);
  for (int i = 0; i < 7; i++) sort((pos[i]).begin(), (pos[i]).end());
  pw[0] = 1;
  for (int i = 1; i < 13; i++) pw[i] = pw[i - 1] * 10;
  scanf("%lld", &n);
  cnt2 = -1;
  dfs2(0);
  printf("%lld\n", cnt2);
  printf("%d\n", ans);
}
