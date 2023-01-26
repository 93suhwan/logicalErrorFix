#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, MOD = 998244353, INF = 0x3f3f3f3f;
int add(int a, int b) {
  return (((long long)a + (long long)b) % MOD + MOD) % MOD;
}
int sub(int a, int b) {
  return (((long long)a - (long long)b) % MOD + MOD) % MOD;
}
int mul(int a, int b) { return 1ll * a * b % MOD; }
int bin(int b, int p) {
  int res = 1;
  for (; p; p >>= 1, b = mul(b, b))
    if (p & 1) res = mul(res, b);
  return res;
}
int T, n, m, a[N];
int cnt[40];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      for (int j = 0; j < 30; j++) {
        cnt[j] += a[i] >> j & 1;
      }
    }
    vector<int> ans;
    for (int k = 1; k <= n; k++) {
      bool ok = 1;
      for (int i = 0; i < 30; i++) {
        if (!cnt[i]) continue;
        if (cnt[i] % k != 0) ok = 0;
        if (!ok) break;
      }
      if (!ok) continue;
      ans.push_back(k);
    }
    for (int x : ans) printf("%d ", x);
    printf("\n");
  }
  return 0;
}
