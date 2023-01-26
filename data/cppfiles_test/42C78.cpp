#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
int N, T;
pair<int, int> en[400005];
int s[400005];
int b[400005];
int bac[400005];
bool tag[400005];
long long d[400005];
void modify(int x, long long val) {
  for (int i = x; i > 0; i -= i & -i) {
    d[i] = (d[i] + val) % MOD;
  }
}
long long query(int x) {
  long long ret = 0;
  for (int i = x; i <= 400000; i += i & -i) {
    ret = (ret + d[i]) % MOD;
  }
  return ret;
}
long long dp[400005];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= (int)(N); ++i) {
    scanf("%d%d", &en[i].second, &en[i].first);
    b[i] = en[i].first;
  }
  sort(en + 1, en + N + 1);
  scanf("%d", &T);
  for (int i = 1; i <= (int)(T); ++i) {
    scanf("%d", &s[i]);
    tag[lower_bound(en + 1, en + N + 1, make_pair(b[s[i]], 0)) - en] = true;
  }
  modify(2 * N, 1);
  for (int i = 1; i <= (int)(N); ++i) {
    dp[i] = query(en[i].second);
    modify(en[i].second, dp[i]);
  }
  int pv = 1;
  long long ret = 0;
  for (int i = N; i > 0; --i) {
    modify(en[i].second, MOD - dp[i]);
    if (tag[i] && en[i].second >= pv) {
      ret = (ret + query(pv)) % MOD;
      pv = en[i].second;
    }
  }
  printf("%lld\n", ret);
  return 0;
}
