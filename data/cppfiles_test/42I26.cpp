#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
struct Node {
  int a, b, id;
};
Node en[400005];
int N, T;
int s[400005];
int bac[400005];
long long d[400005];
void inc(long long& x, long long y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void modify(int x, long long val) {
  for (int i = x; i <= 400000; i += i & -i) {
    inc(d[i], val);
  }
}
long long query(int x) {
  long long ret = 0;
  for (int i = x; i > 0; i -= i & -i) {
    inc(ret, d[i]);
  }
  return ret;
}
long long dp[400005], prv[400005];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= (int)(N); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    en[i] = Node{x, y, i};
    bac[y] = x;
  }
  scanf("%d", &T);
  for (int i = 1; i <= (int)(T); ++i) {
    scanf("%d", &s[i]);
  }
  dp[0] = 0;
  for (int i = 1; i <= 2 * N; ++i) {
    if (bac[i]) {
      dp[i] = (query(i - 1) - query(bac[i] - 1) + 1 + MOD) % MOD;
      modify(bac[i], dp[i]);
    }
    prv[i] = (prv[i - 1] + dp[i]) % MOD;
  }
  set<pair<int, int> > sa, sb;
  for (int i = 1; i <= (int)(T); ++i) {
    sa.insert(make_pair(en[s[i]].a, s[i]));
    sb.insert(make_pair(en[s[i]].b, s[i]));
  }
  int lp = 0;
  long long ret = 0;
  while (sa.size()) {
    int id = sb.rbegin()->second;
    inc(ret, (prv[en[id].b - 1] - prv[lp] + 1 + MOD) % MOD);
    lp = en[id].a;
    while (sa.size() && sa.begin()->first <= lp) {
      id = sa.begin()->second;
      sa.erase(sa.find(make_pair(en[id].a, id)));
      sb.erase(sb.find(make_pair(en[id].b, id)));
    }
  }
  printf("%lld\n", ret);
  return 0;
}
