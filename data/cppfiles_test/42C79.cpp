#include <bits/stdc++.h>
using namespace std;
long long dp[410000];
long long Fa[410000];
long long Ne[410000];
long long tot[410000];
int N;
int Q[210000];
long long mod = 1e9 + 7;
vector<int> V;
void add(int a, long long b) {
  for (int i = a; i <= N; i += (i & -i)) {
    tot[i] = (tot[i] + b) % mod;
    tot[i] = (tot[i] + mod) % mod;
  }
}
long long getsum(int a) {
  long long ans = 0;
  for (int i = a; i > 0; i -= (i & -i)) ans = (ans + tot[i]) % mod;
  return ans;
}
bool cmp(int a, int b) { return Ne[a] > Ne[b]; }
void update(int a, int b) {
  for (int i = a; i <= b; i++) {
    if (Fa[i]) {
      long long c = getsum(Fa[i]) - getsum(Fa[i] - 1);
      c = (c + mod) % mod;
      add(Fa[i], -c);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  N = 2 * n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    Fa[b] = a;
    Ne[a] = b;
    Q[i] = a;
  }
  for (int i = 1; i <= 2 * n; i++)
    if (Fa[i] == 0)
      dp[i] = dp[i - 1];
    else {
      dp[i] = 1 + getsum(i) - getsum(Fa[i] - 1);
      dp[i] %= mod;
      dp[i] = (dp[i] + mod) % mod;
      add(Fa[i], dp[i]);
    }
  long long ans = 0;
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    int a;
    scanf("%d", &a);
    a = Q[a];
    V.push_back(a);
  }
  sort(V.begin(), V.end(), cmp);
  int l = V[0], r = Ne[V[0]];
  update(r, N);
  ans = (ans + getsum(r) - getsum(0)) % mod + mod + 1;
  ans %= mod;
  update(1, l);
  for (auto i : V) {
    if (i <= l) continue;
    update(Ne[i], r);
    r = Ne[i];
    ans = (ans + getsum(r) - getsum(l - 1)) % mod + mod + 1;
    ans %= mod;
    update(l, i);
    l = i;
  }
  printf("%lld\n", ans);
}
